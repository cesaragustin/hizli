#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "debug.h"
#include "hizli.h"
#include "utils.h"

uint32 benchmark(char* filepath_input) {
	FILE* fileIn	= NULL;

	fileIn = fopen(filepath_input, "rb");
	check(fileIn, "No se puede abrir el archivo: %s", filepath_input);

	// determinar el tamaño del archivo input
	fseek(fileIn, 0, SEEK_END);
	uint32 stream_size = ftell(fileIn);
	fseek(fileIn, 0, SEEK_SET);	

	// crear los buffer de memoria de lectura y escritura
	Byte* stream = (Byte *) malloc(sizeof(Byte) * stream_size);
	Byte* stream_compressed = (Byte *) malloc(sizeof(Byte) * (stream_size << 2));
	Byte* stream_uncompressed = (Byte *) malloc(sizeof(Byte) * stream_size);  

	check_mem(stream);
	check_mem(stream_compressed);

	uint32 stream_compressed_size = 0, stream_uncompressed_size = 0;

	uint32 rc;	

	// parámetros de tiempo y velocidad
	clock_t start, end;
	double compression_time, decompression_time;

	fprintf(stdout, "Leyendo archivo %s:%u\n", filepath_input, stream_size);
	rc = fread(stream, sizeof(Byte), stream_size, fileIn);
	check(rc, "Error al leer el archivo: %s", filepath_input); 

	// compresión
	fprintf(stdout, "Comprimiendo archivo %s...\n", filepath_input);
	start = clock();
	rc = hizli_encode(stream, stream_size, stream_compressed, &stream_compressed_size);
	check(rc, "ERROR!\nFalló compression benchmark del archivo: %s", filepath_input);	
	end = clock();		
	compression_time = (double)(end - start)/CLOCKS_PER_SEC;

	fprintf(stdout, "Original size:\t%u MB\n", (stream_size/1024)/1024);
	fprintf(stdout, "Compressed size:\t%u MB\n", (stream_compressed_size/1024)/1024);
	fprintf(stdout, "Compression ratio:\t%.2f %%\n", ((stream_compressed_size/(double)stream_size)) * 100.00);
	fprintf(stdout, "Compression time:\t%.2f s\n", compression_time);
	fprintf(stdout, "Compression rate:\t%.2f MB/s\n", ((stream_size/1024)/1024)/compression_time);

	// descompresión
	start = clock();
	rc = hizli_decode(stream_compressed, stream_compressed_size, stream_uncompressed, &stream_uncompressed_size);
	check(rc, "Falló decompression benchmark del archivo: %s", filepath_input);
	end = clock();		
	decompression_time = (double)(end - start)/CLOCKS_PER_SEC;

	//fprintf(stdout, "Compressed size:\t%u MB\n", (stream_compressed_size/1024)/1024);
	//fprintf(stdout, "Uncompressed size:\t%u MB\n", (stream_uncompressed_size/1024)/1024);
	fprintf(stdout, "Decompression time:\t%.2f s\n", decompression_time);
	fprintf(stdout, "Decompression rate:\t%.2f MB/s\n", ((stream_compressed_size/1024)/1024)/decompression_time);

	fprintf(stdout, "\nFIN\n");

	fclose(fileIn);
	free(stream);
	free(stream_compressed);
	free(stream_uncompressed);
	return 1;
error:
	if(fileIn) fclose(fileIn);
	//if(stream) free(stream);
	//if(stream_compressed) free(stream_compressed);
	//if(stream_uncompressed) free(stream_uncompressed);
	return 0;
}

/**
 * USAGE: ./hizli_tests <options> <file_name>
 * 	c: compress
 *	d: decompress
 *	v: version
 *	u: utils
 */
int main(int argc, char *argv[]) {
	const char *usage = "\nUSAGE: ./hizli_tests <options> <file_input> <file_output>\n\tc: compress\n\td: decompress\n\tb: benchmark\n\tv: version\n"; 
	const char *u_usage = "\nUTILS USAGE: ./hizli_tests u <options> \n\te: check endianness\n";
	check(argc > 1, "%s", usage);

	char action = argv[1][0];
	int rc = 0;

	switch(action) {
		case 'c':
			check(argc == 3 || argc == 4, "%s", usage);			
			rc = prepare_files_to_encode(argv[2], (argc == 3)? "compressed" : argv[3]);
			check(rc, "No fue posible realizar compresion");
			break;
		case 'd':
			check(argc == 3 || argc == 4, "%s", usage);
			rc = prepare_files_to_decode(argv[2], (argc == 3)? "uncompressed" : argv[3]);
			check(rc, "No fue posible realizar descompresion");
			break;
		case 'b':
			check(argc == 3, "%s", usage);
			rc = benchmark(argv[2]);
			check(rc, "No fue posible realizar benchmark");
			break;
		case 'v':
			check(argc == 2, "%s", usage);
		
			fprintf(stdout, "Hizli v.0 - Cesar Gonzalez 2014\n\n");
			break;
		case 'u': 
			check(argc > 2, "%s", u_usage);

			char u_action = argv[2][0];

			switch(u_action) {
				case 'e':
					rc = check_endianness();
					check(rc, "No fue posible checkear endianness");
					break;
				default: 
					sentinel("Utils\nInvalid action. Only e=check endianness");
			} 
			break;
		default:
			sentinel("Invalid action. Only c=compress, d=decompress, b=benchmark, v=version, u=utils");		
	}

	return 0;
error:
	return 1;
}

