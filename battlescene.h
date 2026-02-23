#pragma once
#include "npc.h"
#include "menumenu.h"
#include "player.h"

class BattleScene:public npc, public menumenu, public Player
{
	public:
	
	WINDOW *battleScreen;
	npc* enemy;
	int enemyCount;
	//Player&player;
	
	BattleScene(int enemyC);
	void hpbar();
	void battle();
	
	int attack();
	int items();
	int status();
	int run();
	int battleEND();
	
	~BattleScene();
};
