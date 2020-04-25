//This file changes and reset color.
//the user types in fg for the color theywant.
//Folow this reference: http://www.termys.demon.co.uk.vtansi.htm
#include <stdio.h>
#include "display.h"

int devicestatus(void)
{
	printf("%c[5n", ESC);
	char status[40];
	scanf("%s", status);
	int ret;
	char dum;
	sscanf(status, "%c%c%d%c", &dum, &dum, &ret, &dum);
	return ret;
}

void setfgcolor(int fg)
{
	printf("%c[;%dm", ESC, fg);
}

void setbgcolor (int bg)
{
	printf("%c[1;%dm", ESC, bg);
}

void setcolors(int f, int b)
{
	setfgcolor(f);
	setbgcolor(bg(b));
}

void resetcolor()
{
	printf("%c[0m", ESC);
}

void clearscreen(void)
{
	printf("%c[2J", ESC);
}

void setcursor(int row, int col)
{
	printf("%c[%d;%dH", ESC, row, col);
}

void drawbar(int col, int height)
{
	for (int i = 1; i <= height; i++)
	{
		setcursor(35-i, col);
#ifdef UNICODE
		printf("%s", BAR);
#else
		printf("%c", '|');
#endif
	}
}

Position getscreensize(void){
	Position p;
	char ret[100] = "\0";	//make an empty string for query return
	int r,c;
	setcursor(999,999);
	printf("%c[6n", ESC);	//send query sequence to the terminal
	scanf("%s", ret);
#ifdef DEBUG
	printf("%s\n", ret);
#endif
#include <string.h>
	//the following code will decode the return string from terminal
	if (strlen(ret)>0)
	{
		char dum;
		sscanf(ret, "%c%c%d%c%d%c", &dum, &dum, &r, &dum, &c, &dum);
		p.row = r;
		p.col = c;
	}
	else {
		p.row = 0;
		p.col = 0;
	}
	return p;
}
