//we test functions of display.c
#include <stdio.h>
#include <unistd.h>
#include "display.h"
#include "comm.h"
#include "sound.h"

//use capitalized letters for colors

int main(void)
{
	Position cur = getscreensize();
	char poststr[100];
	sprintf(poststr,  "row=%d&col=%d",cur.row,cur.col);
	senddata(poststr, URL);
	setcursor(1,1);
	printf("Screen size, ROW=%d, COL=%d\n",cur.row, cur.col);
	printf("HTTP post is sent to %s \n", URL);
	getchar();	//waiting for the user to press a key
	getchar();
	for(int i = 1; i <= cur.col/2; i+=2)
	{
		int j = cur.row - i/2-1;
		clearscreen();

		setfgcolor(GREEN);
		setcursor(i/2+1, i);
		printf("%s", REC);
		setcursor(i/2+1, i+1);
		printf("%s", REC);
		setcursor(i/2+1, i+2);
		printf("%s", REC);
		setcursor(i/2+1, i+3);
		printf("%s", REC);

		setfgcolor(RED);
		setcursor(j, i);
		printf("HELLO\n");

		sleep(1);
	}

	for (int i = 0; i < cur.col/2 ; i+=2)
	{
		int j = cur.row - i/2;
		clearscreen();

		setfgcolor(GREEN);
		setcursor(j,i+cur.col/2+1); //last pos = 2*i+1 = 38+1 = 39
		printf("%s", REC);
		setcursor(j,i+cur.col/2+2);
		printf("%s", REC);
		setcursor(j,i+cur.col/2+3);
		printf("%s", REC);
		setcursor(j,i+cur.col/2+4);
		printf("%s", REC);

		setfgcolor(RED);
		setcursor(i/2+1, i+cur.col/2); //last 2*i = 38 + 1
		printf("HELLO\n");

		sleep(1);
	}


	setcursor(12,37);
	setcolors(MAGENTA, BLUE);
	printf("e1900308");
	drawbar(30, 30);
	drawbar(50,30);

	getchar();
	resetcolor();
	clearscreen();
	setcursor(1,1);

	FILE *fp;
	fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	fclose(fp);
	displaywavhdr(h);
}
