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

#ifndef __hizli_h_
#define __hizli_h_

#include <stdint.h>

#if defined(__GNUC__) && (__GNUC__ > 2)
#define HIZLI_PREDICT_TRUE(c)	(__builtin_expect((c), 1))
#define HIZLI_PREDICT_FALSE(c)	(__builtin_expect((c), 0))
#else
#define HIZLI_PREDICT_TRUE(c)	(c)
#define HIZLI_PREDICT_FALSE(c)	(c)
#endif

#define BUFFER_INPUT_SIZE	65536
#define MAX_BUFFER_OUTPUT_SIZE	(BUFFER_INPUT_SIZE << 3) 
#define HASH_SIZE		(BUFFER_INPUT_SIZE >> 1)

#define MAX_LENGTH_COPY		35 	// 66
#define LITERALS_SIZE 		128 	// 32

typedef unsigned char	Byte;
typedef uint16_t 	uint16;
typedef uint32_t 	uint32;
typedef uint64_t 	uint64; 

#define HIZLI_LOAD16(_p) (*(uint16 *)(_p))
#define HIZLI_LOAD32(_p) (*(uint32 *)(_p))
#define HIZLI_LOAD64(_p) (*(uint64 *)(_p))

uint32 prepare_files_to_encode(char* filepath_input, char* filename_output);
uint32 hizli_encode(Byte *input_stream, uint32 input_stream_size, Byte *output_stream, uint32 *output_stream_size);

uint32 prepare_files_to_decode(char* filepath, char* filename_output);
uint32 hizli_decode(Byte *input_stream, uint32 input_stream_size, Byte *output_stream, uint32 *output_stream_size);

#endif

