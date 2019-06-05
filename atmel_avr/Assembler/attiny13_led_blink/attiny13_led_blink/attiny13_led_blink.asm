;  attiny13_led_blink.asm
;  Created: 05.06.2019 21:57:27
;  Author:  sboldenko 

.device ATTINY13A
.include "tn13adef.inc"

.def temp = r16
.def delay0 = r17
.def delay1 = r18

.cseg
.org 0x00 ;начало
;---------------------------- 

INIT:
	ldi temp, 0x01
	out DDRB, temp
MAIN:
	sbi PORTB, 0x00
	rcall DELAY
	cbi PORTB, 0x00
	rcall DELAY
	rjmp MAIN
DELAY:
	dec delay0
	brne DELAY
	dec delay1
	brne DELAY
	ret