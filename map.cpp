#include "terror.h"

Map::Map()
{
	
	mapScreen=create_newwin(16, 32, 2, 118);
	Tile* tile;
}

int Map::mapMove(int mapID, int location[][16], int j, int i)
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
			//case 'i':
			//	Inventory* inventory;
			//	break;
			default: break;
		}
		switch(collision())
		{
			case NORTH: return location[j+1][i];
			case EAST: return location[j][i+1];
			case WEST: return location[j][i-1];
			case SOUTH: return location[j-1][i];
			default: break;
		}
		playerDraw();
		wrefresh(mapScreen);
		keypressed=getch();
		
		
	}
	return 0;
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

int Map::collision()
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
		case TRANSITION_TILE_NORTH: return NORTH;
		case TRANSITION_TILE_EAST: return EAST;
		case TRANSITION_TILE_WEST: return WEST;
		case TRANSITION_TILE_SOUTH: return SOUTH;
		case ENEMY_TILE:
		{
		    BattleScene* battle = new BattleScene(player, 2, KING_OF_DEAD);
		    
		    battle->battleMove();
			
		    tile.noMoreEnemyTile(mapIndex[playerPositionY][playerPositionX]);
		    delete battle;
		    return true;
		}
	}
	return false;
}