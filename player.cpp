#include "terror.h"



void Player::increaseLVL()
{
	lvlUP=0;
	xp=xp+xpEnemy;
	while (xpRequired>=xp)
	{
		if (xp%xpRequired>=2)
		{
			xp=xp-xpRequired;
		}
		lvlUP++;
	}
	lvl=lvl+lvlUP;
	lvlUP=0;
}