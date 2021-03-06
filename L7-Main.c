/* Main.c file generated by New Project wizard
 *
 * Created:   mié oct 26 2016
 * Processor: PIC18F4550
 * Compiler:  MPLAB XC8
 */

#include <xc.h>
#define _XTAL_FREQ 8000000 // Need for __delay_ms function
#include <stdlib.h> // Need for … just check yourself
#include <string.h> // Need for string manipulation
#include <stdio.h>
#include "config.h"
#include "GLCD.h"
#include "ascii.h"
//#include "Bart.h"
#include "building.h"
//#include "car.h"
//#include "Picasso.h"

void SetDot(byte x, byte y) { // Turn on pixel (x,y)
   byte page = x/8; //64 pixels/8 pages = 8 pages d'alçada de 8 pixels cada page
   byte auxiliar = readByte(page,y); //
   writeByte(page,y, auxiliar | 1 << x%8); 
}

void ClearDot(byte x, byte y) { // Turn off pixel (x,y)
    byte page = x >> 3; // dividir entre 8
    byte auxiliar = readByte(page, y);
    writeByte(page, y, auxiliar & (1 << x%8 ));
    }
 
// Escriu el caracter c en la posicio (x,y) (x= 0 a 7) (y= 0 a 20)
// Els caracters estan definits en la taula font5x7[] 
void Putch(byte page, byte y, char c) { 
   int x = (c-32)*5;
    int i;
    for(i = 0; i < 5; ++i){
        writeByte(page, y + i,font5x7[x+i]);
    }
} 

 void writeTxt(byte page, byte y, char * text) {
    int i;
    int x = strlen(text);
    for (i = 0; i < x; ++i){
        Putch(page, y+(i*5), text[i]);
    }
 }
 
 
void writeNum(byte page, byte y, int valor) {
    char buff[10];
    itoa (buff, valor, 10);
    writeTxt(page , y, buff); 
 } // Write an interger value on GLCD
 
void moveDot(){ // Move a dot on the screen.
   int ri = 0;
   int re = 63;
   int ci = 0;
   int ce = 127;
   int i, j;
   for (i = ri; i <= re; i++) {
		for (j=ci;j<=ce;j++) {
			SetDot(i,j); // pixel [i,j] del LCD a 1
			__delay_ms(5);
			ClearDot(i,j);
		}
   }
}


void info(){ // Write group names, lab code and date
   char buffer[256];
sprintf(buffer,"Sulaiman | Carlos | Pau");
writeTxt(0,0,&buffer[0]);
sprintf(buffer,"*****************");
writeTxt(1,0,&buffer[0]);
sprintf(buffer,"23b");   
writeTxt(2,8,&buffer[0]);
sprintf(buffer,"*****************");
writeTxt(3,0,&buffer[0]);
sprintf(buffer,"26/10/2016");
writeTxt(4,5,&buffer[0]);
}

void image(){ // Write the image at bitmap array on the screen
int i = 0;
   for(int page=0; page < 8; ++page){
      for(int y=0; y < 128; ++y){
	 writeByte(page,y,bitmap[i++]);
      }
   }
}

void InitPIC () { // Initialize PORT’s and basic PIC resources
   ADCON1 = 0x0F;
   TRISD = 0x00;
   TRISB = 0x00;
}

void main(void) {
InitPIC(); // Inicialitzar el PIC 
GLCDinit(); // GLCD routines are in rutines_GLCD.c
clearGLCD(0, 7, 0, 127);
setStartLine(0);
image();
//info();
//moveDot();

// MAIN LOOP
while (1) {
 // do the right action
};
}
