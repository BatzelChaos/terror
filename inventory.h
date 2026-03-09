#include "terror.h"

class Inventory
{
	public:
	int menuLimitX;
	int menuLimitY;
	int menu;
	WINDOW* inventoryScreen;
	Inventory();
	int inventoryMove();
};