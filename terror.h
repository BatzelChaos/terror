#define MAIN_MENU 0
#define SETTINGS 1
#define CREDITS 2
#define EXIT 3
#define NEW_GAME 4

#define AUDIO 6
#define GRAPHICS 17
#define RESET 8
#define BACK 9
#define WINDOW_SIZE 18
#define COLOR_SELECT 19

#define ATTACK 100
#define ITEMS 101
#define STATUS 102
#define RUN 103

void wmvprintw(WINDOW *screen, int y, int x, const char *text)

{
	wmove(screen, y, x);
	wprintw(screen, "%s", text);
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;
			
	local_win=newwin(height,width,starty,startx);
	wborder(local_win,'|','|','-','-','o','o','o','o');
	wrefresh(local_win);
			
	return local_win;
}
		
int random(int r)
{
	return rand()%r;
}

/*
enum class KW {
	MENU  = 1
}

KW::MENU
*/

//MAKE A RECURSIVE SELF-GENERATING MENU SCREEN TEMPLATE
//SO I CAN WRITE A SIMPLE menu("a", gotoX, "b", gotoY) THEN GET THE
//INTENDED SELECTION BOXES AND MAKE THEM GO TO THE INTENDED PLACES

template <typename T> T menuMove(T t)
{
	WINDOW *tempScreen;
	int bufferX=15;
	int bufferY=25;
	bufferX=titlePlacement(bufferX); //same as x
	tempScreen=create_newwin(8, 20, bufferY, bufferX);
	wmvprintw(tempScreen, 1, 1, "New Game");
	wmvprintw(tempScreen, 2, 1, "Settings");
	wmvprintw(tempScreen, 3, 1, "Credits");
	wmvprintw(tempScreen, 4, 1, "Exit");
	switch(t)
	{
		case t: 
			wmove(tempScreen, 1, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"New Game");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return NEW_GAME; 
			break;
		} 
	wrefresh(tempScreen);
	return MAIN_MENU;
}