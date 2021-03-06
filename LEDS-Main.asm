        config PLLDIV   = 2         ; (8 MHz crystal on EASYPIC6 board)
        config CPUDIV   = OSC1_PLL2   ; No dividim. Treballem a 8MHz
         config USBDIV   = 2         ; Clock source from 96MHz PLL/2
         config FOSC     = HS	;sense PLL
         config FCMEN    = OFF
         config IESO     = OFF
         config PWRT     = OFF
         config BOR      = ON
         config BORV     = 3
         config VREGEN   = ON      ;USB Voltage Regulator
         config WDT      = OFF
         config WDTPS    = 32768
         config MCLRE    = ON
         config LPT1OSC  = OFF
         config PBADEN   = OFF
;       config CCP2MX   = ON
         config STVREN   = ON
         config LVP      = OFF
;       config ICPRT    = OFF       ; Dedicated In-Circuit Debug/Programming
         config XINST    = OFF       ; Extended Instruction Set
         config CP0      = OFF
         config CP1      = OFF
;       config CP2      = OFF
;       config CP3      = OFF
         config CPB      = OFF
;       config CPD      = OFF
         config WRT0     = OFF
         config WRT1     = OFF
;       config WRT2     = OFF
;       config WRT3     = OFF
         config WRTB     = OFF       ; Boot Block Write Protection
         config WRTC     = OFF
;       config WRTD     = OFF
         config EBTR0    = OFF
         config EBTR1    = OFF
;       config EBTR2    = OFF
;       config EBTR3    = OFF
         config EBTRB    = OFF
	 
;====================================================================
; Main.asm file generated by New Project wizard
;
; Created:   sá. oct. 8 2016
; Processor: PIC18F4550
; Compiler:  MPASM (Proteus)
;====================================================================

;====================================================================
; DEFINITIONS
;====================================================================

#include p18f4550.inc                ; Include register definition file

;====================================================================
; VARIABLES
;====================================================================

;====================================================================
; RESET and INTERRUPT VECTORS
;====================================================================

      ; Reset Vector
RST   code  0x0 
      goto  Start

;====================================================================
; CODE SEGMENT
;====================================================================

PGM   code
Start

      MOVLW 0x0F
      MOVWF ADCON1,0 ;I/O digitals
      MOVLW 0xFF
      MOVWF TRISB,0 ;PORTB IN
      MOVLW 0x00
      MOVWF TRISA,0 ;PORTA OUT
mentre
      MOVF PORTB, 0, 0 ;W<--PORTB
      BZ   mentre
      XORWF PORTA, 1, 0
espera
      MOVF PORTB, 0, 0 ;W<--PORTB
      BNZ espera
      goto mentre

      ;====================================================================
      END
