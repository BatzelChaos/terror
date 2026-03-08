#include "terror.h"


using namespace std;

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
WINDOW* menuFunc_drawWindow(int windowType, int& menuLimitY, int& menuLimitX)
{
	int textBoxPosY, textBoxPosX, textBoxSizeY, textBoxSizeX;
	WINDOW* menuScreen;
	
	switch(windowType)
	{
		case MAIN_MENU:
			textBoxPosY = 20; textBoxPosX = 70;
			textBoxSizeY = 8; textBoxSizeX = 20;
			
			menuLimitY=3; menuLimitX=0;
			break;
		case BATTLE_SELECT:
			textBoxPosY = 34 ; textBoxPosX = 10;
			textBoxSizeY = 8; textBoxSizeX = 103;
			
			menuLimitY=3; menuLimitX=0;
			break;
		case INVENTORY:
			break;    
		case CREDITS:
			textBoxPosY = 15; textBoxPosX = 45;
			textBoxSizeY = 8; textBoxSizeX = 40;
			
			menuLimitY=0, menuLimitX=0;
			break;
		case CHARACTER_SELECT:
			textBoxPosY = 1; textBoxPosX = 9;
			textBoxSizeY = 42; textBoxSizeX = 140;
			
			menuLimitY=20; menuLimitX=105;
			break;
			
		case BATTLE:
			textBoxPosY = 9; textBoxPosX = 8;
			textBoxSizeY = 34; textBoxSizeX = 107;
			
			menuLimitY=0; menuLimitX=4;
			break;
	}
	menuScreen=create_newwin(textBoxSizeY, textBoxSizeX, textBoxPosY, textBoxPosX);
	return menuScreen;
}

void menuFunc(int menu, int menuX, int& menuType, bool enterpressed, int textPositionY, int textPositionX, WINDOW* tempScreen, int menuVar, int returnVar, const char* textVar)
{
	wmvprintw(tempScreen, textPositionY, textPositionX, textVar);
	if(menu==(textPositionY-1)&&menuX==(textPositionX-1))
	{
		wmove(tempScreen, textPositionY, textPositionX);
		wattron(tempScreen, A_STANDOUT);
		wprintw(tempScreen, "%s", textVar);
		wattroff(tempScreen, A_STANDOUT);
		if (enterpressed==true) 
		{

			menuType=returnVar;
			return;
		}	
	}
	if (menuType==CHARACTER_SELECT)
	{
		if(menu==(textPositionY*20+1)&&menuX==(textPositionX*35+1))
		{
			wmove(tempScreen, textPositionY, textPositionX);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen, "%s", textVar);
			wattroff(tempScreen, A_STANDOUT);
			if (enterpressed==true) 
			{
	
				menuType=returnVar;
				return;
			}	
		}
	}
	wrefresh(tempScreen);
}

int main()
{
	srand(time(0));
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