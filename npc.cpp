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
		case KING_OF_DEAD:
			npcname="King Of Dead";
			hp=120; atk=18; def=5; spd=10; xpEnemy=100;
			break;
		case SKELETON_LOW:
			npcname="Skeleton";
			hp=3; atk=1; def=1; spd=1; xpEnemy=1;
			break;
		default:
			npcname="404 - NOT FOUND";
			hp= 999; atk=999; def=999; spd=999; xpEnemy=100;
			break;
	}
}

