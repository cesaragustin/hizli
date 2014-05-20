#include <stdio.h>
#include "utils.h"

typedef union {
	short short_16;				// [______16______]
	unsigned char char_8[sizeof(short)];	// [___8__][___8__]
} endianness;

int check_endianness(void) {
	endianness e;
 
	e.short_16 = 0xFF00;			// 1111 1111 0000 0000 en binario
 
	(e.char_8[0] == 0x00 && e.char_8[1] == 0xFF)? 
		fprintf(stdout, "Little endian\n"):
	
	fprintf(stdout, "Big endian\n");

    	return 1;
}

