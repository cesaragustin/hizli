/*
 * Copyright (c) 2014, César Agustín González Gutiérrez
 * Supported by Fondecyt Grant 11121556, Chile.
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
#include <assert.h>

#include "debug.h"
#include "hizli.h"

uint32 Decompress(Byte *input, uint32 input_size, Byte *output, uint32 *output_size) {
	Byte *ihead 	= input;
	Byte *limit 	= input + input_size - 1;

	Byte *ohead	= output;

	uint32 literals	= 0;

	uint32 length	= 0;	
	uint32 bytes	= 0;
	uint32 offset	= 0;
	uint32 side	= 0;

	for( ; ; ){
		// Lee un literal
		if(((*ihead) & 128) == 128){
			literals = (*ihead) & 127;
			ihead++;
			
			switch(literals){
				case 127:
					*(ohead +127)	= (Byte) *(ihead +127);
				case 126:
					*(ohead +126)	= (Byte) *(ihead +126);
				case 125:
					*(ohead +125)	= (Byte) *(ihead +125);
				case 124:
					*(ohead +124)	= (Byte) *(ihead +124);
				case 123:
					*(ohead +123)	= (Byte) *(ihead +123);
				case 122:
					*(ohead +122)	= (Byte) *(ihead +122);
				case 121:
					*(ohead +121)	= (Byte) *(ihead +121);
				case 120:
					*(ohead +120)	= (Byte) *(ihead +120);
				case 119:
					*(ohead +119)	= (Byte) *(ihead +119);
				case 118:
					*(ohead +118)	= (Byte) *(ihead +118);
				case 117:
					*(ohead +117)	= (Byte) *(ihead +117);
				case 116:
					*(ohead +116)	= (Byte) *(ihead +116);
				case 115:
					*(ohead +115)	= (Byte) *(ihead +115);
				case 114:
					*(ohead +114)	= (Byte) *(ihead +114);
				case 113:
					*(ohead +113)	= (Byte) *(ihead +113);
				case 112:
					*(ohead +112)	= (Byte) *(ihead +112);
				case 111:
					*(ohead +111)	= (Byte) *(ihead +111);
				case 110:
					*(ohead +110)	= (Byte) *(ihead +110);
				case 109:
					*(ohead +109)	= (Byte) *(ihead +109);
				case 108:
					*(ohead +108)	= (Byte) *(ihead +108);
				case 107:
					*(ohead +107)	= (Byte) *(ihead +107);
				case 106:
					*(ohead +106)	= (Byte) *(ihead +106);
				case 105:
					*(ohead +105)	= (Byte) *(ihead +105);
				case 104:
					*(ohead +104)	= (Byte) *(ihead +104);
				case 103:
					*(ohead +103)	= (Byte) *(ihead +103);
				case 102:
					*(ohead +102)	= (Byte) *(ihead +102);
				case 101:
					*(ohead +101)	= (Byte) *(ihead +101);
				case 100:
					*(ohead +100)	= (Byte) *(ihead +100);
				case 99:
					*(ohead +99)	= (Byte) *(ihead +99);
				case 98:
					*(ohead +98)	= (Byte) *(ihead +98);
				case 97:
					*(ohead +97)	= (Byte) *(ihead +97);
				case 96:
					*(ohead +96)	= (Byte) *(ihead +96);
				case 95:
					*(ohead +95)	= (Byte) *(ihead +95);
				case 94:
					*(ohead +94)	= (Byte) *(ihead +94);
				case 93:
					*(ohead +93)	= (Byte) *(ihead +93);
				case 92:
					*(ohead +92)	= (Byte) *(ihead +92);
				case 91:
					*(ohead +91)	= (Byte) *(ihead +91);
				case 90:
					*(ohead +90)	= (Byte) *(ihead +90);
				case 89:
					*(ohead +89)	= (Byte) *(ihead +89);
				case 88:
					*(ohead +88)	= (Byte) *(ihead +88);
				case 87:
					*(ohead +87)	= (Byte) *(ihead +87);
				case 86:
					*(ohead +86)	= (Byte) *(ihead +86);
				case 85:
					*(ohead +85)	= (Byte) *(ihead +85);
				case 84:
					*(ohead +84)	= (Byte) *(ihead +84);
				case 83:
					*(ohead +83)	= (Byte) *(ihead +83);
				case 82:
					*(ohead +82)	= (Byte) *(ihead +82);
				case 81:
					*(ohead +81)	= (Byte) *(ihead +81);
				case 80:
					*(ohead +80)	= (Byte) *(ihead +80);
				case 79:
					*(ohead +79)	= (Byte) *(ihead +79);
				case 78:
					*(ohead +78)	= (Byte) *(ihead +78);
				case 77:
					*(ohead +77)	= (Byte) *(ihead +77);
				case 76:
					*(ohead +76)	= (Byte) *(ihead +76);
				case 75:
					*(ohead +75)	= (Byte) *(ihead +75);
				case 74:
					*(ohead +74)	= (Byte) *(ihead +74);
				case 73:
					*(ohead +73)	= (Byte) *(ihead +73);
				case 72:
					*(ohead +72)	= (Byte) *(ihead +72);
				case 71:
					*(ohead +71)	= (Byte) *(ihead +71);
				case 70:
					*(ohead +70)	= (Byte) *(ihead +70);
				case 69:
					*(ohead +69)	= (Byte) *(ihead +69);
				case 68:
					*(ohead +68)	= (Byte) *(ihead +68);
				case 67:
					*(ohead +67)	= (Byte) *(ihead +67);
				case 66:
					*(ohead +66)	= (Byte) *(ihead +66);
				case 65:
					*(ohead +65)	= (Byte) *(ihead +65);
				case 64:
					*(ohead +64)	= (Byte) *(ihead +64);
				case 63:
					*(ohead +63)	= (Byte) *(ihead +63);
				case 62:
					*(ohead +62)	= (Byte) *(ihead +62);
				case 61:
					*(ohead +61)	= (Byte) *(ihead +61);
				case 60:
					*(ohead +60)	= (Byte) *(ihead +60);
				case 59:
					*(ohead +59)	= (Byte) *(ihead +59);
				case 58:
					*(ohead +58)	= (Byte) *(ihead +58);
				case 57:
					*(ohead +57)	= (Byte) *(ihead +57);
				case 56:
					*(ohead +56)	= (Byte) *(ihead +56);
				case 55:
					*(ohead +55)	= (Byte) *(ihead +55);
				case 54:
					*(ohead +54)	= (Byte) *(ihead +54);
				case 53:
					*(ohead +53)	= (Byte) *(ihead +53);
				case 52:
					*(ohead +52)	= (Byte) *(ihead +52);
				case 51:
					*(ohead +51)	= (Byte) *(ihead +51);
				case 50:
					*(ohead +50)	= (Byte) *(ihead +50);
				case 49:
					*(ohead +49)	= (Byte) *(ihead +49);
				case 48:
					*(ohead +48)	= (Byte) *(ihead +48);
				case 47:
					*(ohead +47)	= (Byte) *(ihead +47);
				case 46:
					*(ohead +46)	= (Byte) *(ihead +46);
				case 45:
					*(ohead +45)	= (Byte) *(ihead +45);
				case 44:
					*(ohead +44)	= (Byte) *(ihead +44);
				case 43:
					*(ohead +43)	= (Byte) *(ihead +43);
				case 42:
					*(ohead +42)	= (Byte) *(ihead +42);
				case 41:
					*(ohead +41)	= (Byte) *(ihead +41);
				case 40:
					*(ohead +40)	= (Byte) *(ihead +40);
				case 39:
					*(ohead +39)	= (Byte) *(ihead +39);
				case 38:
					*(ohead +38)	= (Byte) *(ihead +38);
				case 37:
					*(ohead +37)	= (Byte) *(ihead +37);
				case 36:
					*(ohead +36)	= (Byte) *(ihead +36);
				case 35:
					*(ohead +35)	= (Byte) *(ihead +35);
				case 34:
					*(ohead +34)	= (Byte) *(ihead +34);
				case 33:
					*(ohead +33)	= (Byte) *(ihead +33);
				case 32:
					*(ohead +32)	= (Byte) *(ihead +32);	
				case 31:
					*(ohead +31)	= (Byte) *(ihead +31);
				case 30:
					*(ohead +30)	= (Byte) *(ihead +30);
				case 29:
					*(ohead +29)	= (Byte) *(ihead +29);
				case 28:
					*(ohead +28)	= (Byte) *(ihead +28);
				case 27:
					*(ohead +27)	= (Byte) *(ihead +27);
				case 26:
					*(ohead +26)	= (Byte) *(ihead +26);
				case 25:
					*(ohead +25)	= (Byte) *(ihead +25);
				case 24:
					*(ohead +24)	= (Byte) *(ihead +24);
				case 23:
					*(ohead +23)	= (Byte) *(ihead +23);
				case 22:
					*(ohead +22)	= (Byte) *(ihead +22);
				case 21:
					*(ohead +21)	= (Byte) *(ihead +21);
				case 20:
					*(ohead +20)	= (Byte) *(ihead +20);
				case 19:
					*(ohead +19)	= (Byte) *(ihead +19);
				case 18:
					*(ohead +18)	= (Byte) *(ihead +18);
				case 17:
					*(ohead +17)	= (Byte) *(ihead +17);
				case 16:
					*(ohead +16)	= (Byte) *(ihead +16);
				case 15:
					*(ohead +15)	= (Byte) *(ihead +15);
				case 14:
					*(ohead +14)	= (Byte) *(ihead +14);
				case 13:
					*(ohead +13)	= (Byte) *(ihead +13);
				case 12:
					*(ohead +12)	= (Byte) *(ihead +12);
				case 11:
					*(ohead +11)	= (Byte) *(ihead +11);
				case 10:
					*(ohead +10)	= (Byte) *(ihead +10);
				case 9:
					*(ohead +9)	= (Byte) *(ihead +9);
				case 8:
					*(ohead +8)	= (Byte) *(ihead +8);
				case 7:
					*(ohead +7)	= (Byte) *(ihead +7);
				case 6:
					*(ohead +6)	= (Byte) *(ihead +6);
				case 5:
					*(ohead +5)	= (Byte) *(ihead +5);
				case 4:
					*(ohead +4)	= (Byte) *(ihead +4);
				case 3:
					*(ohead +3)	= (Byte) *(ihead +3);
				case 2:
					*(ohead +2)	= (Byte) *(ihead +2);
				case 1:
					*(ohead +1)	= (Byte) *(ihead +1);
				case 0:
					*(ohead)	= (Byte) *(ihead);
				break;					
			}

			ohead += (literals+1);
			ihead += (literals+1);

		// Lee una copia
		} else {
			// Longitud de la copia
			length = (((*ihead) >> 1) & 31);
			// Tamaño en bytes que compone el offset
			bytes = (((*ihead) >> 6) & 1);
			// Dirección de lectura del offset 			
			side = ((*ihead) & 1);
			ihead++;
		
			if(length == 31) { // length == 35
				length = 31;
				while(*(ihead) == 255) { length += 255; ihead++; }
				length += (uint32) (*(ihead++));
			}	

			// Se lee el offset de acuerdo al tamaño en bytes
			switch(bytes) {
				case 0:
					offset = (uint32) (*(ihead));
					++ihead;
				break;
				case 1:
					offset = (uint32) (*(ihead +1) << 8 | *(ihead));
					ihead+=2;
				break;		
			}

			if(side)
				offset = (ohead - output) - offset;
						
			uint32 len = length+4;

			while(len > 31) {
				*(ohead) 	= (Byte) (*(output +offset));
				*(ohead +1) 	= (Byte) (*(output +offset+1));
				*(ohead +2) 	= (Byte) (*(output +offset+2));
				*(ohead +3) 	= (Byte) (*(output +offset+3));
				*(ohead +4) 	= (Byte) (*(output +offset+4));
				*(ohead +5) 	= (Byte) (*(output +offset+5));
				*(ohead +6) 	= (Byte) (*(output +offset+6));
				*(ohead +7) 	= (Byte) (*(output +offset+7));
				*(ohead +8) 	= (Byte) (*(output +offset+8));
				*(ohead +9) 	= (Byte) (*(output +offset+9));
				*(ohead +10) 	= (Byte) (*(output +offset+10));
				*(ohead +11) 	= (Byte) (*(output +offset+11));
				*(ohead +12) 	= (Byte) (*(output +offset+12));
				*(ohead +13) 	= (Byte) (*(output +offset+13));
				*(ohead +14) 	= (Byte) (*(output +offset+14));
				*(ohead +15) 	= (Byte) (*(output +offset+15));
				*(ohead +16) 	= (Byte) (*(output +offset+16));
				*(ohead +17) 	= (Byte) (*(output +offset+17));
				*(ohead +18) 	= (Byte) (*(output +offset+18));
				*(ohead +19) 	= (Byte) (*(output +offset+19));
				*(ohead +20) 	= (Byte) (*(output +offset+20));
				*(ohead +21) 	= (Byte) (*(output +offset+21));
				*(ohead +22) 	= (Byte) (*(output +offset+22));
				*(ohead +23) 	= (Byte) (*(output +offset+23));
				*(ohead +24) 	= (Byte) (*(output +offset+24));
				*(ohead +25) 	= (Byte) (*(output +offset+25));
				*(ohead +26) 	= (Byte) (*(output +offset+26));
				*(ohead +27) 	= (Byte) (*(output +offset+27));
				*(ohead +28) 	= (Byte) (*(output +offset+28));
				*(ohead +29) 	= (Byte) (*(output +offset+29));
				*(ohead +30) 	= (Byte) (*(output +offset+30));
				*(ohead +31) 	= (Byte) (*(output +offset+31));
				len-=32;
				ohead+=32;
				offset+=32;
			}			

			switch(len){
				case 1:
					*(ohead) 	= (Byte) (*(output +offset));
				break;
				case 2:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
				break;
				case 3:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
				break;
				case 4:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
				break;
				case 5:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
				break;	
				case 6:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
				break;
				case 7:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
				break;
				case 8:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
				break;
				case 9:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
				break;
				case 10:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
				break;
				case 11:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
				break;
				case 12:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
				break;
				case 13:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
				break;
				case 14:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
				break;
				case 15:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
				break;
				case 16:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
				break;
				case 17:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
				break;
				case 18:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
				break;
				case 19:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
				break;
				case 20:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
				break;
				case 21:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
				break;
				case 22:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
				break;
				case 23:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
				break;
				case 24:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
					*(ohead +23) 	= (Byte) (*(output +offset+23));
				break;
				case 25:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
					*(ohead +23) 	= (Byte) (*(output +offset+23));
					*(ohead +24) 	= (Byte) (*(output +offset+24));
				break;
				case 26:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
					*(ohead +23) 	= (Byte) (*(output +offset+23));
					*(ohead +24) 	= (Byte) (*(output +offset+24));
					*(ohead +25) 	= (Byte) (*(output +offset+25));
				break;
				case 27:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
					*(ohead +23) 	= (Byte) (*(output +offset+23));
					*(ohead +24) 	= (Byte) (*(output +offset+24));
					*(ohead +25) 	= (Byte) (*(output +offset+25));
					*(ohead +26) 	= (Byte) (*(output +offset+26));
				break;
				case 28:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
					*(ohead +23) 	= (Byte) (*(output +offset+23));
					*(ohead +24) 	= (Byte) (*(output +offset+24));
					*(ohead +25) 	= (Byte) (*(output +offset+25));
					*(ohead +26) 	= (Byte) (*(output +offset+26));
					*(ohead +27) 	= (Byte) (*(output +offset+27));
				break;
				case 29:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
					*(ohead +23) 	= (Byte) (*(output +offset+23));
					*(ohead +24) 	= (Byte) (*(output +offset+24));
					*(ohead +25) 	= (Byte) (*(output +offset+25));
					*(ohead +26) 	= (Byte) (*(output +offset+26));
					*(ohead +27) 	= (Byte) (*(output +offset+27));
					*(ohead +28) 	= (Byte) (*(output +offset+28));
				break;
				case 30:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
					*(ohead +23) 	= (Byte) (*(output +offset+23));
					*(ohead +24) 	= (Byte) (*(output +offset+24));
					*(ohead +25) 	= (Byte) (*(output +offset+25));
					*(ohead +26) 	= (Byte) (*(output +offset+26));
					*(ohead +27) 	= (Byte) (*(output +offset+27));
					*(ohead +28) 	= (Byte) (*(output +offset+28));
					*(ohead +29) 	= (Byte) (*(output +offset+29));
				break;
				case 31:
					*(ohead) 	= (Byte) (*(output +offset));
					*(ohead +1) 	= (Byte) (*(output +offset+1));
					*(ohead +2) 	= (Byte) (*(output +offset+2));
					*(ohead +3) 	= (Byte) (*(output +offset+3));
					*(ohead +4) 	= (Byte) (*(output +offset+4));
					*(ohead +5) 	= (Byte) (*(output +offset+5));
					*(ohead +6) 	= (Byte) (*(output +offset+6));
					*(ohead +7) 	= (Byte) (*(output +offset+7));
					*(ohead +8) 	= (Byte) (*(output +offset+8));
					*(ohead +9) 	= (Byte) (*(output +offset+9));
					*(ohead +10) 	= (Byte) (*(output +offset+10));
					*(ohead +11) 	= (Byte) (*(output +offset+11));
					*(ohead +12) 	= (Byte) (*(output +offset+12));
					*(ohead +13) 	= (Byte) (*(output +offset+13));
					*(ohead +14) 	= (Byte) (*(output +offset+14));
					*(ohead +15) 	= (Byte) (*(output +offset+15));
					*(ohead +16) 	= (Byte) (*(output +offset+16));
					*(ohead +17) 	= (Byte) (*(output +offset+17));
					*(ohead +18) 	= (Byte) (*(output +offset+18));
					*(ohead +19) 	= (Byte) (*(output +offset+19));
					*(ohead +20) 	= (Byte) (*(output +offset+20));
					*(ohead +21) 	= (Byte) (*(output +offset+21));
					*(ohead +22) 	= (Byte) (*(output +offset+22));
					*(ohead +23) 	= (Byte) (*(output +offset+23));
					*(ohead +24) 	= (Byte) (*(output +offset+24));
					*(ohead +25) 	= (Byte) (*(output +offset+25));
					*(ohead +26) 	= (Byte) (*(output +offset+26));
					*(ohead +27) 	= (Byte) (*(output +offset+27));
					*(ohead +28) 	= (Byte) (*(output +offset+28));
					*(ohead +29) 	= (Byte) (*(output +offset+29));
					*(ohead +30) 	= (Byte) (*(output +offset+30));
				break;
			}
			ohead+=len;
		}
		if(ihead > limit) goto _end;
	}

_end:
	// Tamaño descomprimido
	*output_size = ohead - output;

	return 1;
}

uint32 hizli_decode_file(FILE *fileIn, FILE *fileOut){
	
	uint32 uncompressed_size = 0;

	// crear los buffer de memoria de lectura y escritura
	Byte* bi = (Byte *) malloc(sizeof(Byte) * MAX_BUFFER_OUTPUT_SIZE);  
	Byte* bo = (Byte *) malloc(sizeof(Byte) * BUFFER_INPUT_SIZE);

	uint32 bi_size = 0, bo_size = 0;
	uint32 rc = 0;

	rc = fread(&uncompressed_size, sizeof(uint32), 1, fileIn);
	check(rc, "Error al leer bloque");

	while((rc = fread(&bi_size, sizeof(uint32), 1, fileIn))){
		check(rc, "Error al leer bloque");
		rc = fread(bi, sizeof(Byte), bi_size, fileIn);			
		check(rc, "Error al leer bloque");
		rc = Decompress(bi, bi_size, bo, &bo_size);
		check(rc, "Error al descomprimir");
		rc = fwrite(bo, sizeof(Byte), bo_size, fileOut);
		check(rc, "Error al escribir bloque");
		bo_size = 0;
	}

	free(bi);
	free(bo);
	return uncompressed_size;	

error:
	if(bi) free(bi);
	if(bo) free(bo);
	return 0;
}

uint32 hizli_decode(Byte *input_stream, uint32 input_stream_size, Byte *output_stream, uint32 *output_stream_size) {

	// crear los buffer de memoria de lectura y escritura
	Byte* bi = (Byte *) malloc(sizeof(Byte) * MAX_BUFFER_OUTPUT_SIZE);  
	Byte* bo = (Byte *) malloc(sizeof(Byte) * BUFFER_INPUT_SIZE);

	uint32 bi_size = 0, bo_size = 0;

	uint32 read_bytes = 0, written_bytes = 0;
	uint32 rc;

	// Loop Principal
	do {
		memcpy(&bi_size, (input_stream + read_bytes), sizeof(uint32));
		memcpy(bi, (input_stream + read_bytes + sizeof(uint32)), bi_size);		

		read_bytes += (bi_size + sizeof(uint32));
	
		// Descompresión del chunk de memoria
		rc = Decompress(bi, bi_size, bo, &bo_size);
		check(rc, "Error al descomprimir");

		memcpy((output_stream + written_bytes), bo, bo_size);

		written_bytes += bo_size;

		*output_stream_size += bo_size;

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


uint32 prepare_files_to_decode(char* filepath_input, char* filename_output) {
	FILE* fileIn	= NULL;
	FILE* fileOut	= NULL; 

	fileIn = fopen(filepath_input, "rb");
	check(fileIn, "No se puede abrir el archivo: %s", filepath_input);

	fileOut = fopen(filename_output, "wb");
	check(fileOut, "No se puede crear el archivo: %s", filename_output);

	uint32 rc = hizli_decode_file(fileIn, fileOut);

	fclose(fileIn);
	fclose(fileOut);
	return rc;

error:
	if(fileIn) fclose(fileIn);
	if(fileOut) fclose(fileOut);
	return 0;	
}

