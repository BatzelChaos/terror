#include "terror.h"

using namespace std;

npc::npc()
{
	
}

void npc::npcInit(int npcID)
{
	switch(npcID)
	{
		case 0:
			npcname="wolf";
			hp=3; atk=1; def=1; spd=1; xpEnemy=1;
			break;
		default:
			npcname="404 - NOT FOUND";
			hp= 999; atk=999; def=999; spd=999; xpEnemy=100;
			break;
	}
}

int npc::hpGet()
{
	return hp;
}