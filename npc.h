#pragma once

using namespace std;

class npc
{
	public:
	string npcname;
	int hp, atk, def, spd;
	int npcID;
	
	int xpEnemy;
	
	npc();
	void npcInit(int npcID);
	int hpGet();
};