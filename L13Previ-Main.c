#include <p18f4550.h>
#include "config.h"

#define _XTAL_FREQ 8000000

#define DADES  PORTBbits.RB0
#define CLOCK  PORTBbits.RB6
#define LATCH  PORTBbits.RB2
#define ENABLE PORTBbits.RB4

#define BLAU  0x3FF00000
#define VERD  0x000FFC00
#define ROIG  0x000003FF
#define BLANC 0x3FFFFFFF
#define NEGRE 0x00000000

unsigned long int color;

void send (unsigned long int color) {
        ENABLE = 1; //Activem
        int i;
        for(i=0; i<32; ++i){
            CLOCK = 0; //clock low
            if(((color >> (31-i))&0x01) == 0x01) DADES = 1;  //Agafem el bit, si es 1, pujem el canal, sino baixem el canal
            else DADES = 0;
            CLOCK = 1;  //clock high
        }
        CLOCK= 0;
        LATCH= 1; //Fet
        ENABLE=0; //Desactivem
        LATCH= 0;
}  

void main() {
ADCON1 = 0x0F;
TRISA = 0xFF;
TRISB = 0x00;
   while(1) {
      if(PORTAbits.RA0) send(BLAU);
      else if (PORTAbits.RA1) send(VERD);
      else if (PORTAbits.RA2) send(ROIG); 
      else if (PORTAbits.RA3) send(BLANC);
      else if (PORTAbits.RA4) send(NEGRE);       
    }	 
}
