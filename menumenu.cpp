#include "terror.h"

using namespace std;


menumenu::menumenu(int height, int width)
{
	enterpressed=false;
	menu=0;
	menuType=0;
	screenHeight=height;
	screenWidth=width;
	
	int starty=(LINES-screenHeight)/2;
	int startx=(COLS-screenWidth)/2;
	
	mainscreen=create_newwin(screenHeight,screenWidth,starty,startx);
	menuScreen = menuFunc_drawWindow(MAIN_MENU, menuLimitY, menuLimitX);
	wmove(mainscreen,1,1);
	wtitle(mainscreen);
	wmvprintw(mainscreen, 1, 1, "v0.0.13 PRE-ALPHA");
	
	/*inData.open("terror.settings");
	string data;
	
	while (inData>>"">>firstTimePlay)
	printw(firstTimePlay);*/
	
}


menumenu::menumenu()
{
	
}



void menumenu::debug()
{
	
}

int menumenu::titlePlacement(int widthTitle)
{
	int titleWidth=widthTitle; //manually checked
	titleStartx=(screenWidth/2)-titleWidth/2;	

	return titleStartx;
}



void menumenu::cleanUp(WINDOW *screen, int Y, int X)
{
	wmove(screen, Y, X); wprintw(screen, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //PLACEHOLDER THING
	borderControl(screen); //BANDAID SOLUTION TO THE ABOVE PROBLEM
	wrefresh(screen); //for now useless, but i'll remove borderControl from here
}


void menumenu::refreshMainScreen()
{
	cleanUp(mainscreen,1,1);
	skullart1();
	wtitle(mainscreen);
	wrefresh(mainscreen);
}

int menumenu::resetSettings()
{
	//reset the changes of the settings in the file to set values
	return SETTINGS;
}

int menumenu::audio()
{
	return SETTINGS;
}

int menumenu::colorSelect()
{
	return GRAPHICS;
}

int menumenu::windowSize()
{
	return GRAPHICS;
}

int menumenu::settings()
{
	menuFunc(menu, menuX, menuType, enterpressed, 1, 1, menuScreen, RESET, "Reset");
	menuFunc(menu, menuX, menuType, enterpressed, 2, 1, menuScreen, AUDIO, "Audio");
	menuFunc(menu, menuX, menuType, enterpressed, 3, 1, menuScreen, GRAPHICS, "Graphics");
	menuFunc(menu, menuX, menuType, enterpressed, 4, 1, menuScreen, MAIN_MENU, "Back");

	return menuType;
}

int menumenu::graphics()
{
	menuFunc(menu, menuX, menuType, enterpressed, 1, 1, menuScreen, COLOR_SELECT, "Color Select");
	menuFunc(menu, menuX, menuType, enterpressed, 2, 1, menuScreen, GRAPHICS, "placeholder");
	menuFunc(menu, menuX, menuType, enterpressed, 3, 1, menuScreen, WINDOW_SIZE, "Graphics");
	menuFunc(menu, menuX, menuType, enterpressed, 4, 1, menuScreen, SETTINGS, "Back");

	return menuType;
}

int menumenu::credits()
{
	menuFunc_drawWindow(CREDITS, menuLimitY, menuLimitX);
	menuFunc(menu, menuX, menuType, enterpressed, 1, 1, menuScreen, MAIN_MENU, "Everything: BatzelChaos (ME!)");
	menuFunc(menu, menuX, menuType, enterpressed, 2, 1, menuScreen, MAIN_MENU, "Special thanks to the ncurses\n library and all the tutorials");
	wgetch(menuScreen);
	skullart1();
	wtitle(mainscreen);
	wrefresh(mainscreen);
	return menuType;
}

int menumenu::mainMenu()
{   //bool enterpressed,||int textPosition, WINDOW* tempScreen, int menuVar,|| int returnVar, const char* textVar
	menuFunc(menu, menuX, menuType, enterpressed, 1, 1, menuScreen, NEW_GAME, "     New Game     ");
	menuFunc(menu, menuX, menuType, enterpressed, 2, 1, menuScreen, SETTINGS, "     Settings     ");
	menuFunc(menu, menuX, menuType, enterpressed, 3, 1, menuScreen, CREDITS, "     Credits      ");
	menuFunc(menu, menuX, menuType, enterpressed, 4, 1, menuScreen, EXIT, "       Exit       ");

	return menuType;
}

int menumenu::pauseMenu()
{
	menuFunc(menu, menuX, menuType, enterpressed, 1, 1, menuScreen, RESUME, "Resume");
	menuFunc(menu, menuX, menuType, enterpressed, 2, 1, menuScreen, SETTINGS, "Settings");
	menuFunc(menu, menuX, menuType, enterpressed, 3, 1, menuScreen, PAUSE_MENU, "PLACEHOLDER");
	menuFunc(menu, menuX, menuType, enterpressed, 4, 1, menuScreen, EXIT, "Exit");

	return menuType;
}


int menumenu::mainMenuMove()
{
	int keypressed;
	bool inloop=true;
	menu=1;
	menuX=1;
	
	borderControl(menuScreen);

	while(inloop==true)
	{	
		switch(keypressed)
		{
			case KEY_UP:
				menu--;
				if(menu<=1) menu=1;
				break;
			case KEY_DOWN:
				menu++;
				if(menu>=menuLimitY) menu=menuLimitY;
				break;
			case KEY_RIGHT:
				menuX++;
				if(menuX>=menuLimitX) menuX=menuLimitX;
				break;
			case KEY_LEFT:
				menuX--;
				if(menuX<=1) menuX=1;
				break;
			//case 27: //ESCAPE_KEY
			//	return EXIT;
			case 10: //KEY_ENTER
				enterpressed=true;
				switch(menuType)
				{
					case MAIN_MENU:
						menuType=mainMenu();
						break;
					case SETTINGS:
						menuType=settings();
						break;
					case GRAPHICS:
						menuType=graphics();
						break;
					case COLOR_SELECT:
						menuType=colorSelect();
						break;
					case WINDOW_SIZE:
						menuType=windowSize();
						break;
					case CREDITS:
						menuType=credits();
						break;
					case RESET:
						menuType=resetSettings();
						break;
					case AUDIO:
						menuType=audio();
						break;
					case EXIT:
						endwin();
					case NEW_GAME:
						menuType = play();
						break;
					case PAUSE_MENU:
						menuType = pauseMenu();
						if (menuType==EXIT) return EXIT;
						else if (menuType==RESUME) return RESUME;
						break;
				}
				menu=0; 
				enterpressed=false;
				werase(menuScreen);
				borderControl(menuScreen);
				break;
			default: break;
		}
		switch(menuType)
		{
			case MAIN_MENU:
				mainMenu();
				break;
			case SETTINGS: 
				settings();
				break;
			case CREDITS: 
				credits();
				break;
			case GRAPHICS:
				graphics();
				break;
			case COLOR_SELECT:
				colorSelect();
				break;
			case WINDOW_SIZE:
				windowSize();
				break;
			case EXIT: 
				return EXIT;
			case NEW_GAME:
				return NEW_GAME;
			case PAUSE_MENU:
				pauseMenu();
				break;
		}
		wrefresh(mainscreen);
		keypressed=getch();
		
	}
	return 0;
}


int menumenu::menuInitialise()
{
	//werase(mainscreen);
	skullart1();
	wtitle(mainscreen);
	borderControl(mainscreen);
	
	enterpressed=false;
	menu=0; menuX=0;
	menuType=MAIN_MENU;
	wrefresh(mainscreen);
	int gamestate=0; //0 is menu
	while(gamestate==0) // 4 is NEW_GAME
	{ //3 is exit
		gamestate=mainMenuMove();
	}
	return gamestate;
}

int menumenu::play()
{
	int bufferX=bufferXmenu;
	int bufferY=bufferYmenu;
	bufferX=titlePlacement(bufferX); //same as x
	//update the placement!
	werase(mainscreen);
	borderControl(mainscreen);
	
	mapIndexingInit();
	
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+00, 1+titleStartx/2, "Welcome to Terror, a world where the powers that");
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+01, 1+titleStartx/2, "rule are in decline and the entire world is about to flip");
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+02, 1+titleStartx/2, "upside down, and only the worthy shall live to tell the");
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+03, 1+titleStartx/2, "tale... Will you rise to the challenge?");
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+05, 1+titleStartx/2, "[ PRESS ANY KEY TO CONTINUE... ]");
	wrefresh(mainscreen);
	napms(textSpeed);
	

	
	wgetch(mainscreen);
	
	menuType = CHARACTER_SELECT;
	CharacterSelect* tempCharSelect = new CharacterSelect(mainscreen);
	selectedCharacter = tempCharSelect -> characterSelectMove();
	delete tempCharSelect;
			
	Map* map = new Map(this);
			
	werase(mainscreen);
	borderControl(mainscreen);
	wrefresh(mainscreen);
	
	chatAdder=1;
	int y=0; int x=0;
	
	switch(selectedCharacter)
	{
		case BIENE:
			/*
			wmvprintw(mainscreen, chatAdder, 1, "Exiled from the Hive after the uprising of your sister, you wander through the streets of the");chatAdder++;
			wmvprintw(mainscreen, chatAdder, 1, "Human Empire, almost broke with little fame to your name aside from your impressive height.");chatAdder++;
			wmvprintw(mainscreen, chatAdder, 1, "...");chatAdder++;
			wmvprintw(mainscreen, chatAdder, 1, "You wake up in an inn, the nightmares of the last day at the Hive plaguing your mind.");chatAdder++;
			wmvprintw(mainscreen, chatAdder, 1, "Your temporary adobe has your trusty Hammer-Spear, an Apple and your Coat.");chatAdder++;
			wmvprintw(mainscreen, chatAdder, 1, "..."); chatAdder++;
			wmvprintw(mainscreen, chatAdder, 1, "Commands: look, take, go, speak."); chatAdder++;
			*/
			while (true)
			{
				int tempValue = location[y][x];
				switch(location[y][x])
				{
					case INN_EMPIRE:
						wmvprintw(mainscreen, chatAdder, 1, "...");chatAdder++;
						location[y][x] = map -> mapMove(INN_EMPIRE, y, x);
						break;
					case INN_EMPIRE_ROOMA:
						wmvprintw(mainscreen, chatAdder, 1, "...");chatAdder++;
						location[y][x] = map -> mapMove(INN_EMPIRE_ROOMA, y, x);
						break;
				}
			}
	}
	return EXIT; //ENDS THE GAME
}

void menumenu::setmenuType(int m)
{
	menuType = m;
}

void menumenu::mapIndexingInit()
{
	location[0][0]=INN_EMPIRE;
	location[0][1]=INN_EMPIRE_ROOMA;
	location[0][2]=INN_EMPIRE_ROOMB;
	location[0][3]=INN_EMPIRE_ROOMC;
}