; attiny13_button_led.asm
; Created: 06.06.2019 14:11:51
; Author:  sboldenko

.device ATTINY13A
.include "tn13adef.inc"

.def temp = r16
.cseg
.org 0x00

INIT:
	ldi temp, 0x01
	out DDRB, temp
MAIN:
	rjmp MAIN



