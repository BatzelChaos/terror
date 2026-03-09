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
	wmove(mainscreen,1,1);
	wtitle(mainscreen);
	
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

void menumenu::borderControl(WINDOW *screen)
{
	wborder(screen,'|','|','-','-','o','o','o','o');
	wrefresh(screen);
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
	menuFunc(menu, menuX, menuType, enterpressed, 1, 1, menuScreen, NEW_GAME, "New Game");
	menuFunc(menu, menuX, menuType, enterpressed, 2, 1, menuScreen, SETTINGS, "Settings");
	menuFunc(menu, menuX, menuType, enterpressed, 3, 1, menuScreen, CREDITS, "Credits");
	menuFunc(menu, menuX, menuType, enterpressed, 4, 1, menuScreen, EXIT, "Exit");

	return menuType;
}

int menumenu::characterSelect()
{
	menuFunc_drawWindow(CHARACTER_SELECT, menuLimitY, menuLimitX);
	menuFunc(menu, menuX, menuType, enterpressed, 1, 1, menuScreen, BIENE, 
	"Biene, the Exiled Princess"
"\n ████████            ███████████  "
"\n █████████▓     ▒   ████████████  "
"\n ██████            ██████▒██████  "
"\n ████              ████     █████ "
"\n ███                         ████ "
"\n ██                           ████"
"\n █         ▓▒▓░               ████"
"\n ▓     █░▓     █ █████▓        ███"
"\n ▓  █ ███      █████▒█  █      ███"
"\n █ ░ ██  █     ████  ████▒     ███"
"\n █▒ ███  ▓    ▓████  ████▓     ███"
"\n ██ ███  ████ █████  ███▓█    ████"
"\n ███ █           ██     ▓▒   █▓███"
"\n █  █▒              ██▒▓       ███"
"\n █   ░█           █     █   ▓ ████"
"\n █ █            ░█    ████   ░   ██"
"\n  █     █▒█     ▓██▓ ▓██ ░  █ █  ██"
"\n          ██ ▓ ██████    █  █    ██"
"\n                            █    ██");
	borderControl(menuScreen);
	menuFunc(menu, menuX, menuType, enterpressed, 21, 1, menuScreen, CARTAL, "Cartal, the Cursed");
	menuFunc(menu, menuX, menuType, enterpressed, 1, 36, menuScreen, KANIEL, "Kaniel, the Fallen Angel");
	menuFunc(menu, menuX, menuType, enterpressed, 21, 36, menuScreen, ALBERT, "Albert, the Bloody Knight");
	menuFunc(menu, menuX, menuType, enterpressed, 1, 71, menuScreen, PH1, "Albert, the Bloody Knight");
	menuFunc(menu, menuX, menuType, enterpressed, 21, 71, menuScreen, PH2, "Albert, the Bloody Knight");
	menuFunc(menu, menuX, menuType, enterpressed, 1, 106, menuScreen, PH3, "Albert, the Bloody Knight");
	menuFunc(menu, menuX, menuType, enterpressed, 21, 106, menuScreen, PH4, "Albert, the Bloody Knight");
	
	wrefresh(menuScreen);
	//wgetch(menuScreen);
	return menuType;
}

int menumenu::mainMenuMove()
{
	int keypressed;
	bool inloop=true;
	menu=1;
	menuX=1;
	
	while(inloop==true)
	{
		menuScreen = menuFunc_drawWindow(MAIN_MENU, menuLimitY, menuLimitX);
		
		if(gameBootedUpFirstTime==true) 
		{
			gameBootedUpFirstTime=false;
			mainMenu();
		}
		//refreshMainScreen();
		//causes flickering
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
					case EXIT: //might do something with this
						break;
					case NEW_GAME: //and this one, idk tho
						play();
						break;
				}
				menu=0; 
				enterpressed=false;
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
		}
		//borderControl(mainscreen);
		wrefresh(mainscreen);
		keypressed=getch();
		
	}
	return 0;
}

/*
int menumenu::menuMove(int menuYincrease, int menuXincrease)
{
	int keypressed;
	bool inloop=true;
	menu=0;
	menuX=0;
	while(inloop==true)
	{
		keypressed=getch();
		//refreshMainScreen();
		//causes flickering
		switch(keypressed)
		{
			case KEY_UP:
				menu=menu-menuYincrease;
				if(menu<=0) menu=0;
				break;
			case KEY_DOWN:
				menu=menu+menuYincrease;
				if(menu>=menuLimitY) menu=menuLimitY;
				break;
			case KEY_RIGHT:
				menuX=menuX+menuXincrease;
				if(menuX>=menuLimitX) menuX=menuLimitX;
				break;
			case KEY_LEFT:
				menuX=menuX-menuXincrease;
				if(menuX<=0) menuX=0;
				break;
			case 10: //KEY_ENTER
				enterpressed=true;
				menuType=func();
				menu=0; 
				enterpressed=false;
				break;
			default: break;
		}
		func();
		//borderControl(mainscreen);
		wrefresh(mainscreen);
	}
	return 0;
}
*/
int menumenu::characterSelectMove()
{
	int keypressed;
	bool inloop=true;
	menu=0;
	menuX=0;
	while(inloop==true)
	{
		menuScreen = menuFunc_drawWindow(CHARACTER_SELECT, menuLimitY, menuLimitX);
		//refreshMainScreen();
		//causes flickering
		switch(keypressed)
		{
			case KEY_UP:
				menu=menu-20;
				if(menu<=0) menu=0;
				break;
			case KEY_DOWN:
				menu=menu+20;
				if(menu>=menuLimitY) menu=menuLimitY;
				break;
			case KEY_RIGHT:
				menuX=menuX+35;
				if(menuX>=menuLimitX) menuX=menuLimitX;
				break;
			case KEY_LEFT:
				menuX=menuX-35;
				if(menuX<=0) menuX=0;
				break;
			case 10: //KEY_ENTER
				enterpressed=true;
				switch(menuType)
				{
					case CHARACTER_SELECT:
						menuType=characterSelect();
						break;
					case BIENE:
						//playerCharacter=BIENE;
						playBiene();
						break;
				}
				menu=0; 
				enterpressed=false;
				break;
			default: break;
		}
		characterSelect();
		keypressed=getch();
		wrefresh(mainscreen);
		
	}
	return 0;
}

void menumenu::interaction(int interactionItem, int interactionPlace, int interactionCharacter)
{

}

void menumenu::playBiene()
{
	werase(mainscreen);
	borderControl(mainscreen);
	wrefresh(mainscreen);
	
	chatAdder=1;
	bool bieneLoop=true;
	int y=0; int x=0;
	
	wmvprintw(mainscreen, chatAdder, 1, "Exiled from the Hive after the uprising of your sister, you wander through the streets of the");chatAdder++;
	wmvprintw(mainscreen, chatAdder, 1, "Human Empire, almost broke with little fame to your name aside from your impressive height.");chatAdder++;
	wmvprintw(mainscreen, chatAdder, 1, "...");chatAdder++;
	wmvprintw(mainscreen, chatAdder, 1, "You wake up in an inn, the nightmares of the last day at the Hive plaguing your mind.");chatAdder++;
	wmvprintw(mainscreen, chatAdder, 1, "Your temporary adobe has your trusty Hammer-Spear, an Apple and your Coat.");chatAdder++;
	wmvprintw(mainscreen, chatAdder, 1, "..."); chatAdder++;
	wmvprintw(mainscreen, chatAdder, 1, "Commands: look, take, go, speak."); chatAdder++;
	
	Map map;
	
	while (bieneLoop==true)
	{

		switch(location[y][x])
		{
			case INN_EMPIRE:
				wmvprintw(mainscreen, chatAdder, 1, "...");chatAdder++;
				location[y][x] = map.mapMove(INN_EMPIRE, location, y, x);
				break;
			case INN_EMPIRE_ROOMA:
				wmvprintw(mainscreen, chatAdder, 1, "...");chatAdder++;
				location[y][x] = map.mapMove(INN_EMPIRE_ROOMA, location, y, x);
				break;
			
				
			
		}
	}
	//interactionBiene();

}
int menumenu::menuInitialise()
{
	//werase(mainscreen);
	skullart1();
	wtitle(mainscreen);
	
	enterpressed=false;
	menu=0; menuX=0;
	menuType=MAIN_MENU; //0
	mainMenuMove();
	wrefresh(mainscreen);
	//borderControl(mainscreen);
	int gamestate=0; //0 is menu
	while(gamestate==0) // 4 is NEW_GAME
	{ //3 is exit
		gamestate=mainMenuMove();
	}
	return gamestate;
}

void menumenu::help(int helprequest)
{
	switch(helprequest)
	{
		case COMMANDS:
			wmvprintw(mainscreen, chatAdder, 1, "look, take, go, speak"); chatAdder++;
			break;
	}
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
	
	menuType=CHARACTER_SELECT;
	characterSelect();
	characterSelectMove();
	

	WINDOW *tempScreen;
	tempScreen=create_newwin(6, 50, bufferY, bufferX);
	wmvprintw(tempScreen, 1, 1, "Enter your name:");
	

	//menuMove(20, 35, characterSelect);
	
	

	//wgetstr(tempScreen, playerName);
	//cin<<playerName;
	//wmvprintw(tempScreen, 2, 1, playerName);
	wgetch(tempScreen);
	
	//wmvprintw(mainscreen, titleBufferY+04, tit)
	return 0; //CHANGE THIS
}

void menumenu::mapIndexingInit()
{
	location[0][0]=INN_EMPIRE;
	location[0][1]=INN_EMPIRE_ROOMA;
	location[0][2]=INN_EMPIRE_ROOMB;
}