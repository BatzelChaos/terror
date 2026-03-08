#include "terror.h"

BattleScene::BattleScene(int enemyC, int special)
{
	/*
	int screenHeight=30;
	int screenWidth=100;
	int starty=(LINES-screenHeight)/2;
	int startx=(COLS-screenWidth)/2-20;
	
	battleScreen=create_newwin(screenHeight,screenWidth,starty,startx);
	*/
	battleScreen=menuFunc_drawWindow(BATTLE, menuLimitYbattle, menuLimitXbattle);
	battleMenu=menuFunc_drawWindow(BATTLE_SELECT, menuLimitYmenu, menuLimitXmenu);
	
	//careful, both uses the same variable as menu limit!
	
	enemyCount=enemyC;
	enemy= new npc[enemyCount];
	

	switch(special)
	{
		case NONE:
			for(int i = 0;i<enemyCount;i++)
			{
				int randomValue=rand();
				enemy[i].npcInit(randomValue);
			}
			break;
		case KING_OF_DEAD:
			for(int i = 0;i<enemyCount-1;i++)
			{
				enemy[i].npcInit(SKELETON_LOW);
			}
			enemy[1].npcInit(KING_OF_DEAD);
			break;
	}

}

int BattleScene::battleMove()
{
	int keypressed;
	bool inloop=true;
	menu=0;
	menuX=0;
	while(inloop==true)
	{
		switch(keypressed)
		{
			case KEY_UP:
				menu--;
				if(menu<=0) menu=0;
				break;
			case KEY_DOWN:
				menu++;
				if(menu>=enemyCount) menu=enemyCount;
				break;
			case KEY_RIGHT:
				menuX++;
				if(menuX>=0) menuX=0;
				break;
			case KEY_LEFT:
				menuX--;
				if(menuX<=0) menuX=0;
				break;
			case 10: //KEY_ENTER
				enterpressed=true;
				switch(menuType)
				{
					case BATTLE_ATTACK:
						menuType=attack();
						break;
					case BATTLE_SELECT:
						menuType=battleSelect();
						break;
				}
				menu=0; 
				enterpressed=false;
				break;
			default: break;
		}
		switch(menuType)
		{
			case BATTLE_SELECT:
				battleSelect();
				break;
			case BATTLE_ATTACK:
				attack();
				break;
		}
		wrefresh(mainscreen);
		keypressed=getch();
		
	}
	return 0;

}

int BattleScene::battleSelect()
{
	menuFunc(menu, menuX, menuType, enterpressed, 1,1,battleMenu, BATTLE_SELECT, BATTLE_ATTACK, "Attack");
	menuFunc(menu, menuX, menuType, enterpressed, 2,1,battleMenu, BATTLE_SELECT, INVENTORY, "Inventory");
	return menuType;
}

int BattleScene::attack()
{
	menuFunc(menu, menuX, menuType, menuType, 2,2, battleMenu, BATTLE_ATTACK, BATTLE_ATTACK, "ENEMY");
	return menuType;
}

void BattleScene::hpbar()
{
	int buffer1 = 5;
	
	for(int i = 0;i<enemyCount;i++)
	{
		string a = to_string(enemy[i].hp);
		
		const char* hp = a.c_str();
		wmvprintw(battleScreen, buffer1+i, 4, hp);


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
	player.increaseLVL();
	return BATTLE_END;
}

BattleScene::~BattleScene()
{
	delete[] enemy;
}