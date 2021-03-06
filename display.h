// Usually in a header file we have 2 parts:
// 1. functions declarations
// 2. constant definitions

//constant definitions
#define ESC 0x1B

enum FG {BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

#define bg(c) (c + 10) //this is called macro definition

#define UNICODE
#define BAR "\u2590"
#define REC "\u2588"

#define DEBUG

//the following is the information of cursor position
//this info will be decoded by an escape[6n, and query reply
//should be a string consisting of row and col numbers of the cursor.
typedef struct{
	int row;
	int col;
} Position;
//making a constant in a name will make your program more meaningful/readable
//now we can use color names in function setfgcolor()


//functions declarations
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolor();
void clearscreen();
void setcursor(int, int);
void drawbar(int, int);
Position getscreensize(void);	//this function returns a compound data (2 ints)
int devicestatus(void);
