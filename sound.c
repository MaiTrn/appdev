#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "display.h"

WAVheader readwavhdr(FILE *fp)
{
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displaywavhdr(WAVheader h)
{
	setcursor(1,1);
	printf("Chunk ID: ");
	for (int i = 0; i < 4; i++)
		printf("%c", h.chunkID[i]);
	printf("\nChunk size: %d\n", h.chunkSize);
	printf("Num of channels: %d\n", h.numChannels);
	printf("Block align: %d\n", h.blockAlign);
	printf("Bits per sample: %d\n", h.bitsperSample);
	printf("\nSample rate: %d\n", h.sampleRate);
}
void wavdata(WAVheader h, FILE *fp)
{
	//in this function we will read sound samples from the opened file
	//the samples are calculated into decibel value using Root Mean Square
	//(RMS) formula. We will display a 5-sec recorded sound into bar chart
	//our sound file uses sample rate of 16000 for 5 sec, there are
	//5* 16000 = 80000 samples, we want to display them into 160 bars
	short samples[500];
	int peak = 0;
	int flag = 0;
	for (int i=0; i<160; i++){
		fread(samples, sizeof(samples), 1, fp);
		double sum = 0.0;
		for (int j=0; j<500; j++) {
			sum = sum +  samples[j]* samples[j];
		}
		double re = sqrt(sum/500);
#ifdef SDEBUG
		printf("db[%d] = %f\n", i, 20*log10(re));
#else
		//display bar for re value
		if (20*log10(re) > 60) {
			setfgcolor(RED);
			if (flag == 0)
				peak++;
		}
		else {
			setfgcolor(WHITE);
			flag = 0;
		}
		drawbar(i+1, (int)20*log10(re)/3);
#endif
	}
	resetcolor();
	setcursor(8,1);
	printf("Duration: %.2f s\n", (float)h.subchunk2Size/h.byteRate);
	printf("The number of peaks in this soundtrack: %d", peak);
}
