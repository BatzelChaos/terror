#pragma once
#include "terror.h"

class Map:public Player
{
	public:
	WINDOW* mapScreen;
	Player player;
	int mapID;
	Tile tile;
	int RNG;
	int tempY;
	int tempX;

	int menuLimitXmenu, menuLimitYmenu;

	Inventory* inventory = new Inventory;


	
	Map();
	
	int mapMove(int mapID, int j, int i);
	void mapDraw(int mapID);
	int collision();
	void currentMap();
	void playerDraw();
	void playerErase();
	
};