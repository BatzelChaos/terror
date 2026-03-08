#pragma once

using namespace std;

class menumenu
{
	public:
		//PLAYER
		const char *playerName;
	
		//FLAGS
		bool firstTimePlay;		
		//FLAGS END
		
		//SETTINGS
		bool gameBootedUpFirstTime=true;
		int location[16][16];
		int chatAdder;

		int textSpeed=300;	//change this to be stored in a file and loaded in once the program starts
		//SETTINGS END
		
		ifstream inData;
		ofstream outData;
		
		void debug();
		
		int menu, menuX;
		int menuLimitY, menuLimitX;
		int screenWidth;
		int screenHeight;
		bool enterpressed;
		int menuType;      //change the starting height of the title
		int titleBufferY=3; //and the placement of the menu screen. start from +10 at minimum
		int bufferXmenu=15;
		int bufferYmenu=25;
		int titleStartx;
		
		WINDOW *mainscreen;
		WINDOW *menuScreen;
		
		menumenu(int screenHeight, int screenWidth);
		menumenu();
		
		
		void refreshMainScreen();
		void borderControl(WINDOW *screen);
		int titlePlacement(int widthTitle);
		
		void wtitle(WINDOW *screen);
		
		int menuInitialise();
		int mainMenuMove();
		void cleanUp(WINDOW *screen, int Y, int X);
		void skullart1();
		
		//int menuMove(int menuYincrease, int menuXincrease, function<int()> func);		
		//WINDOW* menuFunc_drawWindow(int windowType);
		//void menuFunc(int textPositionY, int textPositionX, WINDOW* tempScreen, int menuVar, int returnVar, const char* textVar);
		
		int mainMenu();
		int credits();
		int settings();
		int play();
		int graphics();
		int colorSelect();
		int windowSize();
		int resetSettings();
		int audio();
		int newGameScreen();
		
		void mapIndexingInit();
		
		int characterSelect();
		int characterSelectMove();
		
		void playBiene();
		void interaction(int interactionItem, int interactionPlace, int interactionCharacter);
		void playKaniel();
		void playCartal();
		void playAlbert();
		
		void help(int request);
};