#include "terror.h"

void Tile::tileType(TileType tileType)
{
	typeStored=tileType;
	switch(typeStored)
	{
		case WALL_TILE:
			isCollision = true;
			isTreasure = false;
			hasEnemy = false;
			hasTrap = false;
			break;
		case EMPTY_TILE:
			isCollision = false;
			isTreasure = false;
			hasEnemy = false;
			hasTrap = false;
			break;
		case TREASURE_TILE:
			isCollision = false;
			isTreasure = true;
			hasEnemy = false;
			hasTrap = false;
			break;
		case ENEMY_TILE:
			isCollision = false;
			isTreasure = false;
			hasEnemy = true;
			hasTrap = false;
			break;
		case DANGER_TILE:
			isCollision = false;
			isTreasure = false;
			hasEnemy = true;
			hasTrap = true;
			break;
	}
}

void Tile::tileDraw(int y, int x,TileType tileEnter, WINDOW* mapScreen)
{
	tileType(tileEnter);
	wattroff(mapScreen, A_STANDOUT);
	switch(typeStored)
	{
		case WALL_TILE:
			wmvprintw(mapScreen, y, x, "██");
			break;
		case EMPTY_TILE:
			wmvprintw(mapScreen, y, x, "  ");
			break;
		case TREASURE_TILE:
			wmvprintw(mapScreen, y, x, "{}");
			break;
		case ENEMY_TILE:
			wmvprintw(mapScreen, y, x, "!!");
			break;
		case DANGER_TILE:
			wmvprintw(mapScreen, y, x, "!!");
			break;
		case TRANSITION_TILE_NORTH:
			wmvprintw(mapScreen, y, x, "^^");
			break;
		case TRANSITION_TILE_EAST:
			wmvprintw(mapScreen, y, x, "->");
			break;
		case TRANSITION_TILE_WEST:
			wmvprintw(mapScreen, y, x, "<-");
			break;
		case TRANSITION_TILE_SOUTH:
			wmvprintw(mapScreen, y, x, "VV");
			break;
	}
}

void Tile::tileMap(int mapID, int mapIndex[][16], WINDOW* mapScreen)
{
	for(int yscreen=1; yscreen<15; yscreen++)
	{
		for(int xscreen = 1; xscreen<15; xscreen++)
		{
			int ytile=yscreen;
			int xtile=xscreen*2;
			tileDraw(ytile, xtile, EMPTY_TILE, mapScreen);
			mapIndex[yscreen][xscreen]=EMPTY_TILE;
			switch(mapID)
			{
				case INN_EMPIRE:
					if(ytile==1||ytile==14)
					{
						tileDraw(ytile, xtile, WALL_TILE, mapScreen);
						mapIndex[yscreen][xscreen]=WALL_TILE;
					}
					if(xtile==6&&ytile==7)
					{
						tileDraw(ytile, xtile, ENEMY_TILE, mapScreen);
						mapIndex[yscreen][xscreen]=ENEMY_TILE;
					}
					if(xtile==28&&ytile==7)
					{
						tileDraw(ytile, xtile, TRANSITION_TILE_EAST, mapScreen);
						mapIndex[yscreen][xscreen]=TRANSITION_TILE_EAST;
					}
					break;
			}
		}
	}
}

int Tile::tileCollision(int playerPosY, int playerPosX, int mapIndex[][16])
{
	
	switch (mapIndex[playerPosY][playerPosX])
	{
		case EMPTY_TILE: return EMPTY_TILE;
		case WALL_TILE: return WALL_TILE;
		case ENEMY_TILE: return ENEMY_TILE;
		case TRANSITION_TILE_NORTH: return TRANSITION_TILE_NORTH;
		case TRANSITION_TILE_EAST : return TRANSITION_TILE_EAST;
		case TRANSITION_TILE_WEST : return TRANSITION_TILE_WEST;
		case TRANSITION_TILE_SOUTH: return TRANSITION_TILE_SOUTH;

	}
	return EMPTY_TILE;
}

void Tile::noMoreEnemyTile(int mapIndex)
{
	mapIndex=EMPTY_TILE;
}