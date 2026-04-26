#pragma once

enum Items
{
	BROKEN_KNIFE,
};

#define COAT_BIENE 500
#define APPLE 501
#define HAMMER_SPEAR_BIENE 502
#define HONEY 504
#define LESSER_HEALING_POTION 505
#define MEDIUMHEALING_POTION 506
#define GREATER_HEALING_POTION 507
#define MAX_HEALING_POTION 508

enum Locations
{
	INN_EMPIRE,
	INN_EMPIRE_ROOMA,
	INN_EMPIRE_ROOMB,
	INN_EMPIRE_ROOMC,
	STORE_EMPIRE,
	DUNGEON_NEARBY_EMPIRE_A,
	DUNGEON_NEARBY_EMPIRE_B
};

enum TileType
{
	WALL_TILE,
	EMPTY_TILE,
	TREASURE_TILE,
	ENEMY_TILE,
	DANGER_TILE,

	TRANSITION_TILE_NORTH,
	NORTH,
	TRANSITION_TILE_EAST,
	EAST,
	TRANSITION_TILE_WEST,
	WEST,
	TRANSITION_TILE_SOUTH,
	SOUTH
	
};

enum EnemyNames
{
	NONE,
	SKELETON_LOW,
	KING_OF_DEAD
};


enum Menu
{
	BATTLE,
	BATTLE_SELECT,
	BATTLE_ATTACK,
	BATTLE_INVENTORY,
	BATTLE_RUN,
	BATTLE_END,
	INVENTORY,
	
	MAIN_MENU,
	SETTINGS,
	CREDITS,
	EXIT,
	NEW_GAME,

	AUDIO,
	GRAPHICS,
	RESET,
	BACK,
	WINDOW_SIZE,
	COLOR_SELECT,
	CHARACTER_SELECT,

	MAP_SCREEN,
	PROFILE_SCREEN,
	PAUSE_MENU,
	RESUME,
};

enum character
{
	BIENE,
	KANIEL,
	CARTAL,
	ALBERT,
	PH1,
	PH2,
	PH3,
	PH4
};


inline int location[32][32];
inline int mapIndex[32][32];


#include <locale.h>
#include <iostream>
#include <fstream>
#include <termios.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include "rapidxml.hpp"

#include "inventory.h"
#include "menumenu.h"
#include "characterselect.h"
#include "npc.h"
#include "player.h"
#include "battlescene.h"
#include "tile.h"
#include "map.h"



//int playerCharacter;



using namespace std;

void wmvprintw(WINDOW *screen, int y, int x, const char *text);

WINDOW *create_newwin(int height, int width, int starty, int startx);

WINDOW *menuFunc_drawWindow(int windowType, int& menuLimitY, int& menuLimitX);

void menuFunc(int menu, int menuX, int& menuType, bool enterpressed, int textPositionY, int textPositionX, WINDOW* tempScreen, int returnVar, const char* textVar);

int borderControl(WINDOW *screen);
//int random(int r)
//{
//	rand(r);
//}

/*
enum class KW {
	MENU  = 1
}

KW::MENU
*/


/*

struct MenuItem
{
	bool enterpressed;
	int windowType;
	int textPosition;
	int menu;
	int caseVar;
	const char* textVar;
	int returnVar;
};

template <typename... Items> int menuFunc(Items... items)
{
	static_assert((std::is_same_v<Items, MenuItem> && ...), "All arguments must be MenuItem");
	
	int screenHeight = 45; int screenWidth = 150; //MAKE THESE DYNAMIC SOMEDAY ALONG WITH THE ONE IN TERROR.CPP
	int textBoxPosY, textBoxPosX, textBoxSizeY, textBoxSizeX;
	
    MenuItem arr[] = { items... };
    for (const auto& items : arr)
    {
		WINDOW *tempScreen;
		tempScreen=create_newwin(textBoxSizeY, textBoxSizeX, textBoxPosY, textBoxPosX);
		wmvprintw(tempScreen, items.textPosition, 1, items.textVar);
		switch(items.windowType)
		{
			case 0: //MAIN MENU
				textBoxPosY = 25; textBoxPosX = 35;
				textBoxSizeY = 8; textBoxSizeX = 20;
				break;
			case 1: //BATTLE MENU
				break;
			case 2: //INVENTORY
				break;    
		}
		wmove(tempScreen, items.textPosition, 1);
		wattron(tempScreen, A_STANDOUT);
		wprintw(tempScreen, "%s", items.textVar);
		wattroff(tempScreen, A_STANDOUT);
	
		
		
		//switch(items.menu) //GIVES THE MENU TEXT
		//{
		//	case items.caseVar: 
		//		wmove(tempScreen, items.textPosition, 1);
		//		wattron(tempScreen, A_STANDOUT);
		//		wprintw(tempScreen, items.textVar);
		//		wattroff(tempScreen, A_STANDOUT);
		//		wrefresh(tempScreen);
				if (items.enterpressed==true) return items.returnVar; 
		//		break;
		//} 
		wrefresh(tempScreen);
    }
	return arr[0].menu;
}
*/





