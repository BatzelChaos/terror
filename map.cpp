#include "terror.h"

Map::Map()
{
	
	mapScreen=create_newwin(16, 32, 2, 118);
	Tile* tile;
}

void Map::mapMove(int mapID)
{
	int keypressed;
	int enterpressed;
	bool inloop=true;
	playerPositionY=8;
	playerPositionX=8;
	tempY = playerPositionY;
	tempX = playerPositionX;
	wattron(mapScreen, A_STANDOUT);
	mapDraw(mapID);
	while(inloop==true)
	{
		playerErase();
		switch(keypressed)
		{
			case KEY_UP:
				tempY--;
				if(tempY<=1) tempY=1;
				if(collision()==true) tempY++;
				playerPositionY=tempY;
				break;
			case KEY_DOWN:
				tempY++;
				if(tempY>=14) tempY=14;
				if(collision()==true) tempY--;
				playerPositionY=tempY;
				break;
			case KEY_RIGHT:
				tempX++;
				if(tempX>=14) tempX=14;
				if(collision()==true) tempX--;
				playerPositionX=tempX;
				break;
			case KEY_LEFT:
				tempX--;
				if(tempX<=0) tempX++;
				if(collision()==true) tempX++;
				playerPositionX=tempX;
				break;
			case 10: //KEY_ENTER
				enterpressed=true;
				playerPositionY=1;
				playerPositionX=1;
				enterpressed=false;
				break;
			default: break;
		}
		playerDraw();
		wrefresh(mapScreen);
		keypressed=getch();
		
		
	}
}

void Map::mapDraw(int mapID)
{
	wmvprintw(mapScreen, playerPositionY, playerPositionX*2, "  "); 
	tile.tileMap(mapID, mapIndex, mapScreen);
}

void Map::currentMap()
{
	
}

void Map::playerDraw()
{
	wattron(mapScreen, A_STANDOUT);
	wmvprintw(mapScreen, playerPositionY, playerPositionX*2, "  ");
}

void Map::playerErase()
{
	wattroff(mapScreen, A_STANDOUT);
	wmvprintw(mapScreen, playerPositionY, playerPositionX*2, "  ");
}

bool Map::collision()
{
	/*
	if (playerPositionY < 0 || playerPositionY >= 16 ||
        playerPositionX < 0 || playerPositionX >= 32)
    {
        return true;
    }
*/
	
	switch (tile.tileCollision(tempY, tempX, mapIndex))
	{
		case EMPTY_TILE: return false; 
		case WALL_TILE: return true;
		case ENEMY_TILE:
			BattleScene battle(2, KING_OF_DEAD);
			battle.battleMove();
			tile.noMoreEnemyTile(mapIndex[playerPositionY][playerPositionX]);
			return true;
	}
	return false;
}