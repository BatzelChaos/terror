#include "terror.h"

class Inventory
{
	public:
	int menuLimitX;
	int menuLimitY;
	int menu;
	int itemID;
	const char* itemList[30];
	WINDOW* inventoryScreen;
	Inventory();
	int inventoryMove();
	int addItem(int itemID);
	void inventoryRender();
};