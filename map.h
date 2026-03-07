#pragma once
#include "terror.h"

class Map:public Player
{
	public:
	WINDOW* mapScreen;
	int mapID;
	Tile tile;
	int mapIndex[16][16];
	int RNG;
	int tempY;
	int tempX;
	
	Map();
	
	void mapMove(int mapID);
	void mapDraw(int mapID);
	bool collision();
	void currentMap();
	void playerDraw();
	void playerErase();
	
};