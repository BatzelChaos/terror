#include "terror.h"

CharacterSelect::CharacterSelect(WINDOW* tempscreen)
{
    characterSelectScreen = tempscreen;
}

int CharacterSelect::characterSelectMove()
{
	characterSelectScreen = menuFunc_drawWindow(CHARACTER_SELECT, menuLimitY, menuLimitX);
	int keypressed;
    menuType= CHARACTER_SELECT;
	menu=0;
	menuX=0;
	while(true)
	{
		characterSelect();
		keypressed=getch();
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
			case KEY_RIGHT:
				menuX++;
				if(menuX>=menuLimitX) menuX=menuLimitX;
				break;
			case KEY_LEFT:
				menuX--;
				if(menuX<=0) menuX=0;
				break;
			case 10: //KEY_ENTER
				enterpressed=true;
				switch(menuType)
				{
					case CHARACTER_SELECT:
						menuType = characterSelect();
						enterpressed=false;
					case BIENE: enterpressed=false; return BIENE;
					case KANIEL: enterpressed=false; return KANIEL;
					default: break;
				}
				werase(characterSelectScreen);
				break;
			default: break;
		}
		wrefresh(mainscreen);
	}
	return 0;
}

int CharacterSelect::characterSelect()
{
	menuFunc_drawWindow(CHARACTER_SELECT, menuLimitY, menuLimitX);
	menuFunc(menu, menuX, menuType, enterpressed, 1, 1, characterSelectScreen, BIENE, 
	"Biene, the Exiled Princess"
"\n █████████▓     ▒   ████████████  "
"\n ██████            ██████▒██████  "
"\n ████              ████     █████ "
"\n ███                         ████ "
"\n ██                           ████"
"\n █         ▓▒▓░               ████"
"\n ▓     █░▓     █ █████▓        ███"
"\n ▓  █ ███      █████▒█  █      ███"
"\n █ ░ ██  █     ████  ████▒     ███"
"\n █▒ ███  ▓    ▓████  ████▓     ███"
"\n ██ ███  ████ █████  ███▓█    ████"
"\n ███ █           ██     ▓▒   █▓███"
"\n █  █▒              ██▒▓       ███"
"\n █   ░█           █     █   ▓ ████"
"\n █ █            ░█    ████   ░   ██");
	menuFunc(menu, menuX, menuType, enterpressed, 17, 1, characterSelectScreen, CARTAL, "Cartal, the Cursed");
	menuFunc(menu, menuX, menuType, enterpressed, 1, 36, characterSelectScreen, KANIEL, "Kaniel, the Fallen Angel");
	menuFunc(menu, menuX, menuType, enterpressed, 17, 36, characterSelectScreen, ALBERT, "Albert, the Bloody Knight");
	menuFunc(menu, menuX, menuType, enterpressed, 1, 71, characterSelectScreen, PH1, "Albert, the Bloody Knight");
	menuFunc(menu, menuX, menuType, enterpressed, 17, 71, characterSelectScreen, PH2, "Albert, the Bloody Knight");
	menuFunc(menu, menuX, menuType, enterpressed, 1, 106, characterSelectScreen, PH3, "Albert, the Bloody Knight");
	menuFunc(menu, menuX, menuType, enterpressed, 17, 106, characterSelectScreen, PH4, "Albert, the Bloody Knight");
	borderControl(characterSelectScreen);
	return menuType;
}
