#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "display.h"
#include "comm.h"

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
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Block align: %d\n", h.blockAlign);
	printf("Bits per sample: %d\n", h.bitsperSample);
}
void wavdata(WAVheader h, FILE *fp)
{
	//in this function we will read sound samples from the opened file
	//the samples are calculated into decibel value using Root Mean Square
	//(RMS) formula. We will display a 5-sec recorded sound into bar chart
	//our sound file uses sample rate of 16000 for 5 sec, there are
	//5* 16000 = 80000 samples, we want to display them into 160 bars
	short samples[500];		//to read 500 samples from wav file
	int peak = 0;			//to count the number of peaks
	int flag = 0;			//to show that you are in a peak
	double maxDB = 0;		//maximum decibel value
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
				peak++;		//got a peak
		}
		else {
			setfgcolor(WHITE);
			flag = 0;
		}
		if (20*log10(re) > maxDB)
		{
			maxDB = 20*log10(re);
		}
		drawbar(i+1, (int)20*log10(re)/3);
#endif
	}
	//display sample rate, duration, no. of peaks on top of the screen
	resetcolor();
	setcursor(1,1);
	printf("Sample Rate: %d\n", h.sampleRate);
	setcursor(1,40);
	printf("Duration: %.2f s\n", (float)h.subchunk2Size/h.byteRate);
	setcursor(1,80);
	printf("Number of peaks: %d", peak);
	setcursor(1, 120);
	printf("Maximum decibel value: %.4lf\n", maxDB);
	char postdata[100];
	//send number of peaks and maximum decibel value with 4 decimal points
	//to the string array
	sprintf(postdata, "peaks=%d&max=%.4lf", peak, maxDB);
	//send the data to the server
	senddata(postdata, sURL);
}

