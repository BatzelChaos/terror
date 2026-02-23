#include "terror.h"


WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;
	
	local_win=newwin(height,width,starty,startx);
	wborder(local_win,'|','|','-','-','o','o','o','o');
	wrefresh(local_win);
	
	return local_win;
}

void wmvprintw(WINDOW *screen, int y, int x, const char *text)

{
	wmove(screen, y, x);
	wprintw(screen, "%s", text);
}

int random(int r)
{
	return rand()%r;
}

using namespace std;
using std::vector;

/*
		GOALS:
		MOVE CLASSES TO THEIR OWN FILE AND FOLDER
		DRAW A HIERARCHY ON A PAPER OR something
		FIX CHARACTER SELECTION SCREEN

*/

















int main()
{
	bool inloop=true;
	initscr();
	refresh();
	cbreak(); //OR raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0); //0 is invisible
				 //1 is visible
				 //2 is very visible
	menumenu GAME(45,150);
	
	int gamestate=GAME.menuInitialise();
	while(inloop==true)
	{
		switch(gamestate)
		{
			case MAIN_MENU: //0 
				gamestate=GAME.menuInitialise();
				break;
			case NEW_GAME: //4
				gamestate=GAME.play();
				break;
			case EXIT: //3
				inloop=false;
				endwin();
				return 0;
		}
	}
	
	endwin();
	return 0;
}