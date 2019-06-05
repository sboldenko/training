;  attiny13_led_blink.asm
;  Created: 05.06.2019 21:57:27
;  Author:  sboldenko 

.device ATTINY13A
.include "tn13adef.inc"

.def temp = r16
.def delay0 = r17
.def delay1 = r18
.def delay2 = r19

.cseg
.org 0x00 ;начало
;---------------------------- 

INIT:
	ldi temp, 0x01
	out DDRB, temp
;MAIN:
;	sbi PORTB, 0x00
;	rcall DELAY
;	cbi PORTB, 0x00
;	rcall DELAY
;	rjmp MAIN
;DELAY:
	;dec delay0
	;breq 0
	;dec delay1
	;brne DELAY
	;dec delay2
	;brne DELAY
	;ret

main:
sbi PORTB, 0x00

cbi PORTB, 0x00
rjmp main