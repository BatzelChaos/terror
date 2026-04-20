#pragma once
#include "terror.h"

class Player:public npc
{
	public:
	
	int playerID;
	int hp, atk, def, spd;
	int lvl, xp, xpRequired, lvlUP;
	int playerPositionX, playerPositionY;
	
	Player();
	
	void increaseLVL();
	void death();
};