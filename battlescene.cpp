#include "terror.h"

BattleScene::BattleScene(int enemyC)
{
	Player player;
	int screenHeight=30;
	int screenWidth=100;
	int starty=(LINES-screenHeight)/2;
	int startx=(COLS-screenWidth)/2-20;
	
	battleScreen=create_newwin(screenHeight,screenWidth,starty,startx);
	
	enemyCount=enemyC;
	enemy= new npc[enemyCount];
	for(int i = 0;i<enemyCount;i++)
	{
		int randomValue=random(5);
		enemy[i].npcInit(randomValue);
	}
}

int BattleScene::attack()
{
	//access skills to choose here

	switch(enemyCount)
	{
		case 1:
			break;
		case 2:
			break;
	}
}

void BattleScene::hpbar()
{
	int buffer1 = 5;
	
	for(int i = 0;i<enemyCount;i++)
	{
		string a = to_string(enemy[i].hp);
		
		const char* hp = a.c_str();
		wmvprintw(battleScreen, buffer1+i, 4, hp);

		//ADD HP BARS I CAN'T THINK RN

		//int localhp=enemy[i].hp;
		//float mappedhp;
		//if (localhp<20) 
		//else 
		//for(int j = 0;j<localhp&&20;j++)
		//{
		//	wmvprintw(battleScreen, buffer1+i, j+2, "|");
		//}
	}
}

void BattleScene::battle()
{
	
}

int BattleScene::battleEND()
{
	increaseLVL();
	return BATTLE_END;
}

BattleScene::~BattleScene()
{
	delete[] enemy;
}