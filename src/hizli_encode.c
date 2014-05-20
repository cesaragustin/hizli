/*
 * Copyright (c) 2014, César Agustín González Gutiérrez
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to
 * endorse or promote products derived from this software without specific prior written
 * permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "debug.h"
#include "hizli.h"

uint32 hash_table[HASH_SIZE] = { 0 };

static inline uint32 HashBytes(uint32 bytes, int shift) {
	uint32 kMul = 0x1e35a7bd;
	return (bytes * kMul) >> shift;
}

static inline uint32 HashFunction(Byte* p, int shift) {
	return HashBytes(HIZLI_LOAD32(p), shift);
}

static inline uint32 Compress(Byte *input, uint32 input_size, Byte *output, uint32 *output_size) {
	Byte *ihead 	= input;
	Byte *limit 	= ihead + input_size - 1;
	Byte *step 	= ihead; 
	
	Byte *ohead	= output;
	Byte *lithead	= ohead++;

	uint32 literals	= 0;

	uint32 length	= 0;	
	uint32 offset	= 0;
	uint32 bytes	= 0;

	uint32 add_new_literal_header = 0; 

	if(input_size == 1) {
		*(ohead++) = (Byte) (128);
		*(ohead++) = (Byte) (*(ihead));

		*output_size = ohead - output;

		return 1;	
	}

	uint32 table_size = HASH_SIZE;
	int shift = 32 - floor(log2(table_size));

	// Se indexan los primeros caracteres
	uint32 hval = HashFunction(ihead, shift);	
	hash_table[hval] = ihead - input;	
	
	/*
	// Los primeros 128 bytes serán literales
	uint32 i = LITERALS_SIZE;
	while(i--) {
		hash_table[HashFunction(ihead, shift)] = (ihead - input);
		*(ohead++) = (Byte) *(ihead++);
	}

	*(lithead) = (Byte) (255);

	add_new_literal_header = 1;	
	*/

	uint32 skip = 1;

	for( ; ; ) {
		/* Literal detectado */
		if(length == 0) {
			if(add_new_literal_header) {
				lithead = ohead++;
				add_new_literal_header = 0;
			}								
		
			skip = 1;

			while(skip--) {
				// repeat
				*(ohead) = (Byte) *(ihead);

				//hash_table[HashFunction(ihead, shift)] = (ihead - input);

				++ohead; 
				++ihead; 
				++literals;
				if(literals == LITERALS_SIZE) {
					*(lithead) = (Byte) ((literals-1) | 128);
					literals = 0;
					add_new_literal_header = 1;
				}
				if(HIZLI_PREDICT_FALSE(ihead > limit)) goto _end;
			}
		/* Copia detectada */		
		} else {
			if(literals) {
				*(lithead) = (Byte) ((literals-1) | 128);
				literals = 0;
			}
			add_new_literal_header = 1;			

			uint32 offset2 = ihead - (input + offset);
			uint32 side = 0;
			if(offset > offset2) { side = 1; offset = offset2; }
			bytes = 1;
			if(offset > UINT8_MAX) bytes = 2;

			if(length > 34) {
				*(ohead++) = (Byte) ((bytes - 1) << 6) | 62 | side;
				length-=35;
				for(;length>254; *(ohead++) = 255, length -= 255);
				*(ohead++) = (Byte) length;
			} else { 
				*(ohead++) = (Byte) ((bytes - 1) << 6) | ((length - 4) << 1) | side;
			}
			
			switch(bytes) {
				case 2: 
					*(ohead+1) = (Byte) (offset >> 8);
				case 1: 
					*(ohead) = (Byte) (offset);			   	
				break;
			}

			ohead += bytes;
			ihead += step - ihead;

			//hash_table[HashFunction(ihead - 4, shift)] = (ihead - 4 - input);
			//hash_table[HashFunction(ihead - 3, shift)] = (ihead - 3 - input);
			//hash_table[HashFunction(ihead - 2, shift)] = (ihead - 2 - input);
			hash_table[HashFunction(ihead - 1, shift)] = (ihead - 1 - input);

			if(HIZLI_PREDICT_FALSE(ihead > limit)) goto _end;
		}	
		
		step = ihead;

		// Busca posición de la copia
		hval = HashFunction(ihead, shift);
		offset = hash_table[hval];
		
		length = 0;

		Byte *candidate = input + offset;
	
		if(candidate < step) {
			if(HIZLI_LOAD32(candidate) == HIZLI_LOAD32(step) && (step + 4) < limit) {
				candidate += 4;
				step += 4;
				for(length = 4; *(candidate) == *(step); candidate++, step++, length++);
			}
		}
		
		hash_table[hval] = (ihead - input);
	}

_end:
	if(literals) {
		*(lithead) = (Byte) ((literals-1) | 128); 
	}

	*output_size = ohead - output;

	return 1;
}

static inline uint32 hizli_encode_file(FILE *fileIn, FILE *fileOut) {
	// determinar el tamaño del archivo input
	fseek(fileIn, 0, SEEK_END);
	uint32 file_size = ftell(fileIn);
	fseek(fileIn, 0, SEEK_SET);	
	uint32 compressed_size = 0;

	// crear los buffer de memoria de lectura y escritura
	Byte* bi = (Byte *) malloc(sizeof(Byte) * BUFFER_INPUT_SIZE);  
	Byte* bo = (Byte *) malloc(sizeof(Byte) * MAX_BUFFER_OUTPUT_SIZE);

	uint32 bi_size = 0, bo_size = 0;

	uint32 rc;
	
	// escribiendo preámbulo en archivo comprimido
	rc = fwrite(&file_size, sizeof(uint32), 1, fileOut);
	check(rc, "Error al escribir preámbulo en archivo");
	
	while((bi_size = fread(bi, sizeof(Byte), BUFFER_INPUT_SIZE, fileIn))) {
		check(rc, "Error al leer bloque");
		rc = Compress(bi, bi_size, bo, &bo_size);
		check(rc, "Error al comprimir");
		rc = fwrite(&bo_size, sizeof(uint32), 1, fileOut);
		check(rc, "Error al escribir bloque");
		rc = fwrite(bo, sizeof(Byte), bo_size, fileOut);
		check(rc, "Error al escribir bloque");
		compressed_size = compressed_size + bo_size;
		bo_size = 0;
	}

	free(bi);
	free(bo);
	return compressed_size;	

error:
	if(bi) free(bi);
	if(bo) free(bo);
	return 0;	
}

uint32 hizli_encode(Byte *input_stream, uint32 input_stream_size, Byte *output_stream, uint32 *output_stream_size) {
		
	// crear los buffer de memoria de lectura y escritura
	Byte* bi = (Byte *) malloc(sizeof(Byte) * BUFFER_INPUT_SIZE);  
	Byte* bo = (Byte *) malloc(sizeof(Byte) * MAX_BUFFER_OUTPUT_SIZE);

	uint32 bi_size = 0, bo_size = 0;

	uint32 read_bytes = 0, written_bytes = 0;
	uint32 rc;
	
	do {
		bi_size = (input_stream_size - read_bytes < BUFFER_INPUT_SIZE)? (input_stream_size - read_bytes) : BUFFER_INPUT_SIZE;
		memcpy(bi, (input_stream + read_bytes), bi_size);
		read_bytes = read_bytes + bi_size;
		rc = Compress(bi, bi_size, bo, &bo_size);
		check(rc, "Error al comprimir");

		memcpy((output_stream + written_bytes), &bo_size, sizeof(uint32));
		memcpy((output_stream + written_bytes + sizeof(uint32)), bo, bo_size);

		written_bytes = written_bytes + (bo_size + sizeof(uint32));

		*output_stream_size = *output_stream_size + (bo_size + sizeof(uint32));

		bo_size = 0;

	} while(input_stream_size > read_bytes);

	free(bi);
	free(bo);
	return 1;

error:
	if(bi) free(bi);
	if(bo) free(bo);
	return 0;
}

uint32 prepare_files_to_encode(char* filepath_input, char* filename_output) {
	FILE* fileIn	= NULL;
	FILE* fileOut	= NULL; 

	fileIn = fopen(filepath_input, "rb");
	check(fileIn, "No se puede abrir el archivo: %s", filepath_input);

	fileOut = fopen(filename_output, "wb");
	check(fileOut, "No se puede crear el archivo: %s", filename_output);
	
	uint32 rc = hizli_encode_file(fileIn, fileOut);

	fclose(fileIn);
	fclose(fileOut);
	return rc;

error:
	if(fileIn) fclose(fileIn);
	if(fileOut) fclose(fileOut);
	return 0;	
}

