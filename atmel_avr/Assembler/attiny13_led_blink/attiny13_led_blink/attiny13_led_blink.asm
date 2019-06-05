;  attiny13_led_blink.asm
;  Created: 05.06.2019 21:57:27
;  Author:  sboldenko 

.device ATTINY13A
.include "tn13adef.inc"

.def temp = r16

.cseg
.org 0x00 ;начало
;---------------------------- 

INIT:
	ldi temp, 0x01
	out DDRB, temp
	sbi PORTB, 0
MAIN:
	rjmp MAIN



