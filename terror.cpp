#include <iostream>
#include <fstream>
#include <termios.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "terror.h"

#include "rapidxml.hpp"

using namespace std;

//class enemy:npc
//{
	
//};

class npc
{
	public:
	string npcname;
	int hp, atk, def, spd;
	int npcID;
	
	npc(int npcID);
	int hpGet();
};

npc::npc(int npcID)
{
	switch(npcID)
	{
		case 0:
			npcname="wolf";
			hp=3; atk=1; def=1; spd=1;
			break;
		default:
			break;
	}
}

int npc::hpGet()
{
	return hp;
}

class BattleScene:public npc
{
	public:
	
	WINDOW *battleScreen;
	int* enemy;
	int enemyCount;
	
	BattleScene(int enemyC);
	void hpbar();
	
	~BattleScene();
};

BattleScene::BattleScene(int enemyC):npc
{
	int screenHeight=30;
	int screenWidth=100;
	int starty=(LINES-screenHeight)/2;
	int startx=(COLS-screenWidth)/2-20;
	
	battleScreen=create_newwin(screenHeight,screenWidth,starty,startx);
	
	enemyCount=enemyC;
	enemy= new int[enemyCount];
	for(int i;i<enemyCount;i++)
	{
		enemy[i]=random(1); //MAKE THIS A DYNAMIC OBJECT
	}
	for(int i;i<enemyCount;i++)
	{
		npc enemy[i](0); //temporary default option
	}
}

void BattleScene::hpbar()
{
	int buffer1=5;
	for(int i;i<enemyCount;i++)
	{
		int localhp=enemy[i].hpGet();
		for(int j;j<localhp;j++)
		{
			wmvprintw(battleScreen, buffer1+i, j, "|");
		}
	}
}

BattleScene::~BattleScene()
{
	delete[] enemy;
}

class menumenu
{
	public:
		//PLAYER
		const char *playerName;
	
		//FLAGS
		bool firstTimePlay;		
		//FLAGS END
		int textSpeed=300;	//change this to be stored in a file and loaded in once the program starts
		
		ifstream inData;
		ofstream outData;
		
		void debug();
		
		int menu;
		int screenWidth;
		int screenHeight;
		bool enterpressed;
		int menuType;      //change the starting height of the title
		int titleBufferY=3; //and the placement of the menu screen. start from +10 at minimum
		int bufferXmenu=15;
		int bufferYmenu=25;
		int titleStartx;
		
		WINDOW *mainscreen;
		
		menumenu(int screenHeight, int screenWidth);
		
		
		void borderControl(WINDOW *screen);
		int titlePlacement(int widthTitle);
		
		void wtitle(WINDOW *screen);
		
		int menuInitialise();
		int mainMenuMove();
		void cleanUp(WINDOW *screen, int Y, int X);
		void skullart1();
		
		int mainMenu();
		int credits();
		int settings();
		int play();
		int graphics();
		int colorSelect();
		int windowSize();
		int resetSettings();
		int audio();
		int newGameScreen();
		
};

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

void menumenu::debug()
{
	BattleScene battle(3);
}

int menumenu::titlePlacement(int widthTitle)
{
	int titleWidth=widthTitle; //manually checked
	titleStartx=(screenWidth/2)-titleWidth/2;	

	return titleStartx;
}

void menumenu::wtitle(WINDOW *screen) //title function
{
	int buffer1=4;
	titlePlacement(58); //width, manually checked
	wmove(screen, buffer1+1, titleStartx); wprintw(screen,"··························································");
	wmove(screen, buffer1+2, titleStartx); wprintw(screen,": ____    ____      ___       ___       ____      ___    :");
	wmove(screen, buffer1+3, titleStartx); wprintw(screen,":/_  _|  F ___J    F _ ',    F _ ',    F __ ]    F _ ',  :");
	wmove(screen, buffer1+4, titleStartx); wprintw(screen,":[J  L] J |___:   J `-'(|   J `-'(|   J |--| L  J `-'(|  :");
	wmove(screen, buffer1+5, titleStartx); wprintw(screen,": |  |  | _____|  |  _  L   |  _  L   | |  | |  |  _  L  :");
	wmove(screen, buffer1+6, titleStartx); wprintw(screen,": F  J  F L____:  F |_|  L  F |_|  L  F L__J J  F |_|  L :");
	wmove(screen, buffer1+7, titleStartx); wprintw(screen,":J____LJ________LJ__| ||__LJ__| ||__LJ|______/FJ__| ||__L:");
	wmove(screen, buffer1+8, titleStartx); wprintw(screen,":|____||________||__|  J__||__|  J__| J______F |__|  J__|:");
	wmove(screen, buffer1+9, titleStartx); wprintw(screen,"··························································");
	
	/*
	empty space to paste-in a possible new title screen
	*/
}

void menumenu::cleanUp(WINDOW *screen, int Y, int X)
{
	wmove(screen, Y, X); wprintw(screen, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //PLACEHOLDER THING
	borderControl(screen); //BANDAID SOLUTION TO THE ABOVE PROBLEM
	wrefresh(screen); //for now useless, but i'll remove borderControl from here
}

void menumenu::borderControl(WINDOW *screen)
{
	wborder(screen,'|','|','-','-','o','o','o','o');
	wrefresh(screen);
}

void menumenu::skullart1()
{
	int buffer1=2;
	titlePlacement(80);
	wmvprintw(mainscreen, buffer1+0, titleStartx, "                              █  ██████████████  █                              ");
	wmvprintw(mainscreen, buffer1+1, titleStartx, "                          █ ████████████████████████ █                          ");
	wmvprintw(mainscreen, buffer1+2, titleStartx, "                        ████████ ██          ██ ████████                        ");
	wmvprintw(mainscreen, buffer1+3, titleStartx, "                      ██████ ██    █        █    ██ ██████                      ");
	wmvprintw(mainscreen, buffer1+4, titleStartx, "	                 ███ ██ █      ██   ██   ██      █ ██ ███                    ");
	wmvprintw(mainscreen, buffer1+5, titleStartx, "                  ██████   ██ █       █▒▒█       █ ██   ██████                  ");
	wmvprintw(mainscreen, buffer1+6, titleStartx, "                 █ ██ █  █  █    █ ████  ████ █    █  █  █ ██ █                 ");
	wmvprintw(mainscreen, buffer1+7, titleStartx, "                █▒██ ██ █ █                          █ █ ██ ██▒█                ");
	wmvprintw(mainscreen, buffer1+8, titleStartx, "               █ ██ █ █▒█     █                  █     █▓█ █ ██ █               ");
	wmvprintw(mainscreen, buffer1+9, titleStartx, "              █ ██   █ █                                █ █   ██ █              ");
	wmvprintw(mainscreen, buffer1+10, titleStartx, "             █ ██  ██               ███  ███               ██  ██ █             ");
	wmvprintw(mainscreen, buffer1+11, titleStartx, "             █ ████     █ ██ ██       █  █       ██ ██ █     ████ █             ");
	wmvprintw(mainscreen, buffer1+12, titleStartx, "              ██ ██   ███  █   ██              ██   █  ███   ██ ██              ");
	wmvprintw(mainscreen, buffer1+13, titleStartx, "              ██ █   ██ ███ ███  █   ██  ██   █  ███ ███ ██   █ ██              ");
	wmvprintw(mainscreen, buffer1+14, titleStartx, "             ██      █████      █ █          █ █      █████ ░    ██             ");
	wmvprintw(mainscreen, buffer1+15, titleStartx, "             ██      ██ ███  ██ ▓█            █▓ ██  ███ ██      ██             ");
	wmvprintw(mainscreen, buffer1+16, titleStartx, "             ██████   █  █   █ █ █            █ █ █   █  █   ██████             ");
	wmvprintw(mainscreen, buffer1+17, titleStartx, "               █ █ ████  █  █████  ▓  █  █  ▓  █████  █  ████ █ █               ");
	wmvprintw(mainscreen, buffer1+18, titleStartx, "               ██  █   ███████ ░     ██████     ░ ███████   █  ██               ");
	wmvprintw(mainscreen, buffer1+19, titleStartx, "                 ██ █    █          ██▒██▒██          █    █ ██                 ");
	wmvprintw(mainscreen, buffer1+20, titleStartx, "                 ███    █      ▒   ███ ██ ███   ▒      █    ███                 ");
	wmvprintw(mainscreen, buffer1+21, titleStartx, "                  ███▓         █  ██ ██  ██ ██  █         ▓███                  ");
	wmvprintw(mainscreen, buffer1+22, titleStartx, "                   █████ █  █      ▒█▓    ▓█▒      █  █ █████                   ");
	wmvprintw(mainscreen, buffer1+23, titleStartx, "                    █ ██     █                    █     ██ █                    ");
	wmvprintw(mainscreen, buffer1+24, titleStartx, "                      ████    █  ▓            █  █    ▓███                      ");
	wmvprintw(mainscreen, buffer1+25, titleStartx, "                     █████    █                  █    █████                     ");
	wmvprintw(mainscreen, buffer1+26, titleStartx, "                     █  ██ █                        █░██  █                     ");
	wmvprintw(mainscreen, buffer1+27, titleStartx, "                      █ █████    █ ████  ████ █    █████ █                      ");
	wmvprintw(mainscreen, buffer1+28, titleStartx, "                     ██ ███ ██████  ██ ██ ██  ██████ ███ ██                     ");
	wmvprintw(mainscreen, buffer1+29, titleStartx, "                    █ █  ████████ ████████████ ████████  █ █                    ");
	wmvprintw(mainscreen, buffer1+30, titleStartx, "                     ███ █ █  ██ ██ ████████ ██ ██  █ █ ███                     ");
	wmvprintw(mainscreen, buffer1+31, titleStartx, "                     ██ ████████ ██████████████ ████████ ██                     ");
	wmvprintw(mainscreen, buffer1+32, titleStartx, "                      █  ▒█████████████  █████████████▒  █                      ");
	wmvprintw(mainscreen, buffer1+33, titleStartx, "                      ██  ███ ████████    ████████ ███  ██                      ");
	wmvprintw(mainscreen, buffer1+34, titleStartx, "                      ██  ░   ███  █ ██████ █  ███   ░  ██                      ");
	wmvprintw(mainscreen, buffer1+35, titleStartx, "                       █  █                          █  █                       ");
	wmvprintw(mainscreen, buffer1+36, titleStartx, "                        ░█                            █▒                        ");
	wmvprintw(mainscreen, buffer1+37, titleStartx, "                       ██ █   █  █            █  █   █ ██                       ");
	wmvprintw(mainscreen, buffer1+38, titleStartx, "                         █ █ █        █  █        █ █ █                         ");
	wmvprintw(mainscreen, buffer1+39, titleStartx, "                           ███  █████ ████ █████  ███                           ");
	wmvprintw(mainscreen, buffer1+40, titleStartx, "                                   █ ██████ █                                   ");
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
	WINDOW *tempScreen;
	int bufferX=bufferXmenu;
	int bufferY=bufferYmenu;
	bufferX=titlePlacement(bufferX); //same as x
	tempScreen=create_newwin(8, 20, bufferY, bufferX);
	wmvprintw(tempScreen, 1, 1, "Audio");
	wmvprintw(tempScreen, 2, 1, "Graphics");
	wmvprintw(tempScreen, 3, 1, "Reset");
	wmvprintw(tempScreen, 4, 1, "Back");
	switch(menu)
	{
		case 0: 
			wmove(tempScreen, 1, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Audio");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return AUDIO; 
			break;
		case 1: 
			wmove(tempScreen, 2, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Graphics");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return GRAPHICS; 
			break;
		case 2: 
			wmove(tempScreen, 3, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Reset");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return RESET; 
			break;
		case 3: 
			wmove(tempScreen, 4, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Back");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return MAIN_MENU;
			break;
	} 
	wrefresh(tempScreen);
	return SETTINGS;
}

int menumenu::graphics()
{
	WINDOW *tempScreen;
	int bufferX=bufferXmenu;
	int bufferY=bufferYmenu;
	bufferX=titlePlacement(bufferX); //same as x
	tempScreen=create_newwin(8, 20, bufferY, bufferX);
	wmvprintw(tempScreen, 1, 1, "Font Color");
	wmvprintw(tempScreen, 2, 1, "Window Size");
	wmvprintw(tempScreen, 3, 1, "a");
	wmvprintw(tempScreen, 4, 1, "Back");
	switch(menu)
	{
		case 0: 
			wmove(tempScreen, 1, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Font Color");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return COLOR_SELECT; 
			break;
		case 1: 
			wmove(tempScreen, 2, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Window Size");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return WINDOW_SIZE; 
			break;
		case 2: 
			wmove(tempScreen, 3, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"a");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return GRAPHICS; 
			break;
		case 3: 
			wmove(tempScreen, 4, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Back");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return SETTINGS;
			break;
	} 
	wrefresh(tempScreen);
	return GRAPHICS;
}

int menumenu::credits()
{
	WINDOW *tempScreen;
	int bufferX=bufferXmenu;
	int bufferY=bufferYmenu;
	bufferX=titlePlacement(bufferX); //same as x
	tempScreen=create_newwin(8, 50, bufferY, bufferX);
	wmvprintw(tempScreen, 1, 1, "Everything: BatzelChaos (ME!)");
	wmvprintw(tempScreen, 3, 1, "Special thanks to the ncurses library and all the tutorials");
	wrefresh(tempScreen);
	wgetch(tempScreen);
	wclear(tempScreen);
	wrefresh(tempScreen);
	return MAIN_MENU;
}

int menumenu::mainMenu()
{
	WINDOW *tempScreen;
	int bufferX=bufferXmenu;
	int bufferY=bufferYmenu;
	bufferX=titlePlacement(bufferX); //same as x
	tempScreen=create_newwin(8, 20, bufferY, bufferX);
	wmvprintw(tempScreen, 1, 1, "New Game");
	wmvprintw(tempScreen, 2, 1, "Settings");
	wmvprintw(tempScreen, 3, 1, "Credits");
	wmvprintw(tempScreen, 4, 1, "Exit");
	switch(menu)
	{
		case 0: 
			wmove(tempScreen, 1, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"New Game");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return NEW_GAME; 
			break;
		case 1: 
			wmove(tempScreen, 2, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Settings");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return SETTINGS; 
			break;
		case 2: 
			wmove(tempScreen, 3, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Credits");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return CREDITS; 
			break;
		case 3: 
			wmove(tempScreen, 4, 1);
			wattron(tempScreen, A_STANDOUT);
			wprintw(tempScreen,"Exit");
			wattroff(tempScreen, A_STANDOUT);
			wrefresh(tempScreen);
			if (enterpressed==true) return EXIT;
			break;
	} 
	wrefresh(tempScreen);
	return MAIN_MENU;
}

int menumenu::mainMenuMove()
{
	int keypressed;
	bool inloop=true;
	menu=0;
	while(inloop==true)
	{
		keypressed=getch();
		switch(keypressed)
		{
			case KEY_UP:
				menu--;
				if(menu<=0) menu=0;
				break;
			case KEY_DOWN:
				menu++;
				if(menu>=3) menu=3;
				break;
			case KEY_LEFT:
				debug();
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
	}
	return 0;
}

int menumenu::menuInitialise()
{
	//werase(mainscreen);
	skullart1();
	wtitle(mainscreen);
	enterpressed=false;
	menu=0;
	menuType=MAIN_MENU; //0
	mainMenu();
	wrefresh(mainscreen);
	//borderControl(mainscreen);
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
	cleanUp(mainscreen,0,0);
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+00, titleStartx, "Welcome to Terror, a world where the powers that rule are");
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+01, titleStartx, "in decline and the entire world is about to flip");
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+02, titleStartx, "upside down, and only the worthy shall live to tell the");
	wrefresh(mainscreen);
	napms(textSpeed);
	wmvprintw(mainscreen, titleBufferY+03, titleStartx, "tale... Will you rise to the challenge?");
	wrefresh(mainscreen);
	napms(textSpeed);
	
		
	WINDOW *tempScreen;
	tempScreen=create_newwin(6, 50, bufferY, bufferX);
	wmvprintw(tempScreen, 1, 1, "Enter your name:");
	//wgetstr(tempScreen, playerName);
	//cin<<playerName;
	//wmvprintw(tempScreen, 2, 1, playerName);
	wgetch(tempScreen);
	
	//wmvprintw(mainscreen, titleBufferY+04, tit)
	return 0; //CHANGE THIS
}

int main()
{
	//height
	//width
	
	srand(100);
	
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