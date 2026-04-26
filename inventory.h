#include "terror.h"

class Inventory
{
	public:
		static Inventory& getInstance()
		{
			static Inventory inventory;
			return inventory;
		}
		Inventory(Inventory const&) = delete;
    	void operator=(Inventory const&) = delete;
		
		int inventoryMove();
		int addItem(int itemID);
		void inventoryRender();
	private:
		Inventory();
		int menuLimitX;
		int menuLimitY;
		int menu;
		int itemID;
		const char* itemList[30];
		WINDOW* inventoryScreen;
};