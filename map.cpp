#include "terror.h"

Map::Map(menumenu* m): menuPointer(m)
{
	
	mapScreen=menuFunc_drawWindow(MAP_SCREEN, tempY, tempX);
	Tile* tile;
	mapDraw(mapID);
}

int Map::mapMove(int mapID, int j, int i)
{
	
	int keypressed;
	int enterpressed;
	bool inloop=true;
	playerPositionY=8;
	playerPositionX=8;
	tempY = playerPositionY;
	tempX = playerPositionX;
	wattron(mapScreen, A_STANDOUT);
	while(inloop==true)
	{
		playerErase();
		switch(keypressed)
		{
			case KEY_UP:
				tempY--;
				if(tempY<=1) tempY=1;
				switch(collision())
				{
					case true: tempY++; break;
					case NORTH: return location[j+1][i];
					case EAST: return location[j][i+1];
					case WEST: return location[j][i-1];
					case SOUTH: return location[j-1][i];
					default: break;
				}
				playerPositionY=tempY;
				break;
			case KEY_DOWN:
				tempY++;
				if(tempY>=30) tempY=30;
				switch(collision())
				{
					case true: tempY--; break;
					case NORTH: return location[j+1][i];
					case EAST: return location[j][i+1];
					case WEST: return location[j][i-1];
					case SOUTH: return location[j-1][i];
					default: break;
				}
				playerPositionY=tempY;
				break;
			case KEY_RIGHT:
				tempX++;
				if(tempX>=30) tempX=30;
				switch(collision())
				{
					case true: tempX--; break;
					case NORTH: return location[j+1][i];
					case EAST: return location[j][i+1];
					case WEST: return location[j][i-1];
					case SOUTH: return location[j-1][i];
					default: break;
				}
				playerPositionX=tempX;
				break;
			case KEY_LEFT:
				tempX--;
				if(tempX<=0) tempX=1;
				switch(collision())
				{
					case true: tempX++; break;
					case NORTH: return location[j+1][i];
					case EAST: return location[j][i+1];
					case WEST: return location[j][i-1];
					case SOUTH: return location[j-1][i];
					default: break;
				}
				playerPositionX=tempX;
				break;
			case 'i':
			{
				int value = Inventory::getInstance().inventoryMove();
				switch(value)
				{
					case 0: break;
				}
				break;
			}
			case 27: //ESCAPE_KEY
				menuPointer -> setmenuType(PAUSE_MENU);
				menuPointer -> mainMenuMove();
		}
		borderControl(mapScreen);
		playerDraw();
		

		wrefresh(mapScreen);
		keypressed=getch();
		
		
	}
	return 0;
}

void Map::mapDraw(int mapID)
{
	wmvprintw(mapScreen, playerPositionY, playerPositionX*2, "  "); 
	tile.tileMap(mapID, mapScreen);
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

int test = 1;

int Map::collision()
{
	/*
	if (playerPositionY < 0 || playerPositionY >= 16 ||
        playerPositionX < 0 || playerPositionX >= 32)
    {
        return true;
    }
*/
	
	switch (tile.tileCollision(tempY, tempX))
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
		    
		    int value = battle->battleMove();
			if (value == BATTLE_END)
			{
				tile.deleteCell(mapIndex[playerPositionY][playerPositionX]);
				delete battle;
				return false;
			}
			else return true;
		    
		}
		case TREASURE_TILE:
			switch(mapID)
			{
				case INN_EMPIRE:
					int value = Inventory::getInstance().addItem(BROKEN_KNIFE);
					if (value==1)
					{
						tile.deleteCell(mapIndex[tempY][tempX]);
						return false; //returns true if the treasure is picked up
					}
					else 
					{
						return true;
					}
			}
			return true; //treasure pickup failed
	}
	return false;
}