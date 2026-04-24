#ifndef TILE_H
#define TILE_H
#pragma once
#include "terror.h"



class Tile//:public menumenu
{
	public:
	TileType typeStored;
	bool isCollision;
	bool isTreasure;
	bool hasEnemy;
	bool hasTrap;
	
	void tileType(TileType type);
	void tileDraw(int y, int x, TileType tile, WINDOW* mapScreen);
	void tileMap(int mapID, WINDOW* mapScreen);
	int tileCollision(int y, int x);
	void deleteCell(int &mapIndex);
};
#endif