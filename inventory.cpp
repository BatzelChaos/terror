#include "terror.h"

Inventory::Inventory()
{
	inventoryScreen = menuFunc_drawWindow(INVENTORY, menuLimitY, menuLimitX);
	werase(inventoryScreen);
	wrefresh(inventoryScreen);
	for(int i=0;i<=30;i++)
	{
		itemList[i]=" ";
	}
}

int Inventory::inventoryMove()
{
	int keypressed;
	bool inloop=true;
	bool enterpressed;
	int menuType;
	menu=0;
	
	while(inloop==true)
	{
		inventoryScreen = menuFunc_drawWindow(INVENTORY, menuLimitY, menuLimitX);
		inventoryRender();
		switch(keypressed)
		{
			case KEY_UP:
				menu--;
				if(menu<=0) menu=0;
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
			case 27: //ESCAPE_KEY
				werase(inventoryScreen);
				wrefresh(inventoryScreen);
				return 0;
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
	for(int i=0;i<=30;i++)
	{
		if(itemList[i]==" ")
		{
			switch(itemID)
			{
				case BROKEN_KNIFE: itemList[i]="Broken Knife"; break;
				default: break;
			}
			return 1; //success
		}
	}
	return 0; //failure
}

void Inventory::inventoryRender()
{
	
	for(int i=0;i<=30;i++)
	{
		wmvprintw(inventoryScreen, i+1, 1, itemList[i]);
	}
}