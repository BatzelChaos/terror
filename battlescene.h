#pragma once
#include "npc.h"
#include "menumenu.h"
#include "player.h"

class BattleScene:public npc, public menumenu
{
	public:
	
	WINDOW *battleScreen;
	WINDOW *battleMenu;
	npc* enemy;
	int enemyCount;
	int currentScreenName;
	int menuLimitX, menuLimitY;
	//Player&player;
	
	BattleScene(int enemyC, int special);
	void hpbar();
	void battle();
	
	int battleMove();
	int battleSelect();
	int attack();
	int items();
	int status();
	int run();
	int battleEND();
	Player player;
	
	~BattleScene();
};
