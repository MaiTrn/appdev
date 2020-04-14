// Usually in a header file we have 2 parts:
// 1. functions declarations
// 2. constant definitions

//constant
#define ESC 0x1B

enum FG {BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

#define bg(c) (c + 10) //this is called macro definition

#define UNICODE
#define BAR "\u2590"
#define REC "\u2588"

#define DEBUG

//information of cursor position
//this info will be decoded by an escape[6n, and query reply
//should be a string consisting of row and col numbers of the cursor.
typedef struct{
	int row;
	int col;
} Position;


//functions
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolor();
void clearscreen();
void setcursor(int, int);
void drawbar(int, int);
Position getscreensize(void);
int devicestatus(void);
