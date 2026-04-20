#include "terror.h"

Player::Player()
{
	lvl=0; xp=0;
	
	hp=10;
	atk=5;
	def=0;
	spd=11;
}

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
