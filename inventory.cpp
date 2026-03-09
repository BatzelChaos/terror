#include "terror.h"

Inventory::Inventory()
(
	inventoryScreen = menuFunc_drawWindow(INVENTORY, menuLimitY, menuLimitX);
)

int Inventory::inventoryMove()
{
	char keypressed;
	bool inloop=true;
	bool enterpressed;
	menu=1;
	
	while(inloop==true)
	{
		inventoryScreen = menuFunc_drawWindow(MAIN_MENU, menuLimitY, menuLimitX);
		
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
			case 'I':
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