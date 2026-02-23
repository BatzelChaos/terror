#include "terror.h"

Map::Map()
{
}

void Map::mapMove()
{
	WINDOW* mapScreen;
	mapScreen=create_newwin(16, 32, 2, 100);

	int posX, posY;
	int keypressed;
	int enterpressed;
	bool inloop=true;
	posY=0;
	posX=0;
	while(inloop==true)
	{
		keypressed=getch();
		//refreshMainScreen();
		//causes flickering
		switch(keypressed)
		{
			case KEY_UP:
				posY++;
				if(posY<=0) posY=0;
				collision();
				break;
			case KEY_DOWN:
				posY--;
				if(posY>=16) posY=16;
				collision();
				break;
			case KEY_RIGHT:
				posX++;
				posX++;
				if(posX>=32) posX=32;
				collision();
				break;
			case KEY_LEFT:
				posX--;
				posX--;
				if(posX<=0) posX=0;
				collision();
				break;
			case 10: //KEY_ENTER
				enterpressed=true;
				posY=0;
				posX=0;
				enterpressed=false;
				break;
			default: break;
		}
		//borderControl(mainscreen);
		wrefresh(mapScreen);
	}
}

void Map::mapDraw()
{
	
}

void Map::collision()
{
	/*
	int posYCol, posXCol;
	switch (posX)
	{
		case 0
	}
	
	if posYCol
	*/
}

void Map::currentMap()
{
	
}