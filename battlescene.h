#pragma once
#include "npc.h"
#include "menumenu.h"
#include "player.h"

class BattleScene: public menumenu
{
	public:
	
	WINDOW *battleScreen;
	WINDOW *battleMenu;
	npc* enemy;
	Player player;
	
	int enemyCount;
	int currentScreenName;
	int menuLimitXbattle, menuLimitYbattle;
	int menuLimitXmenu, menuLimitYmenu;
	//Player&player;
	
	BattleScene(Player& player,int enemyC, int special);
	void hpbar();
	void battle();
	void battleEnemyRender(int ID, int position);
	
	void damageMessage();
	
	int battleMove();
	int battleSelect();
	int attack();
	int items();
	int status();
	int run();
	int battleEND();
	
	~BattleScene();
};
