//we test functions of display.c
#include <stdio.h>
#include <unistd.h>
#include "display.h"
#include "comm.h"
#include "sound.h"

int main(void)
{
	clearscreen();
	FILE *fp;
	fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displaywavhdr(h);
	wavdata(h, fp);		//to calculate db values and display them in a bar chart
	fclose(fp);
	getchar();
	clearscreen();
}
