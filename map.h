#pragma once
#include "terror.h"

class Map:public Player
{
	public:
	WINDOW* mapScreen;
	Player player;
	int mapID;
	Tile tile;
	int mapIndex[16][16];
	int RNG;
	int tempY;
	int tempX;

	int menuLimitXmenu, menuLimitYmenu;

	
	Map();
	
	int mapMove(int mapID, int location[][16], int j, int i);
	void mapDraw(int mapID);
	int collision();
	void currentMap();
	void playerDraw();
	void playerErase();
	
};