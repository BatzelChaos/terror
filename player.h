#pragma once
#include "terror.h"

class Player:public npc, public menumenu
{
	public:
	
	int playerID;
	int hp, atk, def, spd;
	int lvl, xp, xpRequired, lvlUP;
	int playerPositionX, playerPositionY;
	
	void increaseLVL();
	void death();
	
	
};