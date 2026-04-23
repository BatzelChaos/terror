#include "terror.h"

Inventory::Inventory()
{
	inventoryScreen = menuFunc_drawWindow(INVENTORY, menuLimitY, menuLimitX);
	werase(inventoryScreen);
	wrefresh(inventoryScreen);
	//for(int i=0;i<=32;i++)
	//{
	//	itemList[i]=" ";
	//}
}

int Inventory::inventoryMove()
{
	char keypressed;
	bool inloop=true;
	bool enterpressed;
	int menuType;
	menu=1;
	
	while(inloop==true)
	{
		inventoryScreen = menuFunc_drawWindow(INVENTORY, menuLimitY, menuLimitX);
		inventoryRender();
		switch(keypressed)
		{
			case KEY_UP:
				menu--;
				if(menu<=1) menu=1;
				break;
			case KEY_DOWN:
				menu++;
				if(menu>=menuLimitY) menu=menuLimitY;
				break;
			case 'i':
				werase(inventoryScreen);
				wrefresh(inventoryScreen);
				return 0;
			case 10: //KEY_ENTER
				enterpressed=true;
				switch(menuType)
				{
					//case MAIN_MENU:
						//menuType=mainMenu();
						//break
				}
				menu=0; 
				enterpressed=false;
				break;
			default: break;
		}
		switch(menuType)
		{
			//case MAIN_MENU:
			//	mainMenu();
				break;
		}
		wrefresh(inventoryScreen);
		keypressed=getch();
		
	}
	return 0;
}

int Inventory::addItem(int itemID)
{
	for(int i;i<=32;i++)
	{
		if(i==0)
		{
			switch(itemID)
			{
				case BROKEN_KNIFE: itemList[i]="Broken Knife"; break;
				default: break;
			}
			return 1;
		}
	}
	return 0;
}

void Inventory::inventoryRender()
{
	
	for(int i;i<=32;i++)
	{
		wmvprintw(inventoryScreen, i, 2, itemList[i]);
	}
}