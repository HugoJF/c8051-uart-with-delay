#include <stdio.h>
#include "config.c"


void putchar (unsigned char c) {
	SBUF0 = c;
	while (TI0 == 0);
	TI0 = 0;
}

void delay(unsigned int ms) {
	TMOD |= 0x01;
	TMOD &= ~0x02;

	while (ms-- > 0) {
		TR0 = 0;
		TF0 = 0;
		TL0 = 0x58;
		TH0 = 0x9e;
		TR0 = 1;
		while (TF0 == 0);
	}
}


void main (void) {
	unsigned char output = ' '; // start from first visible char

	Init_Device();
	SFRPAGE = LEGACY_PAGE;

	while(1) {
		putchar(output++);
		delay(1000);
	}
}