#pragma once
#include "terror.h"

class Map:public Player
{
	private:
	menumenu* menuPointer;

	public:
	WINDOW* mapScreen;
	Player player;
	int mapID;
	Tile tile;
	int RNG;
	int tempY;
	int tempX;

	int menuLimitXmenu, menuLimitYmenu;


	
	Map(menumenu* m);
	
	int mapMove(int mapID, int j, int i);
	void mapDraw(int mapID);
	int collision();
	void currentMap();
	void playerDraw();
	void playerErase();
	
};