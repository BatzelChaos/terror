#include "terror.h"

BattleScene::BattleScene(Player& player, int enemyC, int special):player(player)
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
	
	
	this->enemyCount=enemyC;
	this->enemy= new npc[enemyCount];
	

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
			enemy[0].npcInit(KING_OF_DEAD);
			battleEnemyRender(KING_OF_DEAD, 3);
			break;
	}

}


int BattleScene::battleMove()
{
	int keypressed;
	bool inloop=true;
	menu=0;
	menuX=0;
	menuType=BATTLE_SELECT;
	//menuScreen = menuFunc_drawWindow(BATTLE_SELECT, menuLimitY, menuLimitX);
		
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
				if(menu>=menuLimitYmenu) menu=menuLimitYmenu;
				break;
			case KEY_RIGHT:
				menuX++;
				if(menuX>=menuLimitXmenu) menuX=menuLimitXmenu;
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
					case BATTLE_RUN:
						menuType=run();
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
			case BATTLE_RUN:
				run();
			case BATTLE_END:
				wclear(battleMenu);
				wrefresh(battleMenu);
				wclear(battleScreen);
				wrefresh(battleScreen);
				return 0;
		}
		wrefresh(battleMenu);
		keypressed=getch();
		
	}
	return 0;

}

int BattleScene::battleSelect()
{
	menuFunc(menu, menuX, menuType, enterpressed, 1,1,battleMenu, BATTLE_ATTACK, "Attack");
	menuFunc(menu, menuX, menuType, enterpressed, 1,11,battleMenu, INVENTORY, "Inventory");
	menuFunc(menu, menuX, menuType, enterpressed, 2,1,battleMenu, BATTLE_RUN, "Run");
	wrefresh(battleMenu);
	return menuType;
}

int BattleScene::attack()
{
	menuFunc(menu, menuX, menuType, enterpressed, 2,2, battleMenu, BATTLE_ATTACK, "ENEMY");
	wrefresh(battleMenu);
	return menuType;
}

void BattleScene::hpbar()
{
	int buffer1 = 5;
	
	for(int i = 0;i<enemyCount;i++)
	{
		string a = to_string(enemy[i].getHP());
		
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

int BattleScene::run()
{
	if (player.getSpeed()>enemy[0].getSpeed())
	{
		return BATTLE_END;
	}
	return BATTLE_SELECT;
}

int BattleScene::battleEND()
{
	player.increaseLVL();
	return BATTLE_END;
}

void BattleScene::battleEnemyRender(int ID, int position)
{
	position=position*10;
	switch(ID)
	{
		case KING_OF_DEAD:
			wmvprintw(battleScreen, 2, position, "    O    ");
			wmvprintw(battleScreen, 3, position, "    O    ");
			wmvprintw(battleScreen, 4, position, "    O    ");
			wmvprintw(battleScreen, 5, position, "    O    ");
			wmvprintw(battleScreen, 6, position, "    O    ");
			wmvprintw(battleScreen, 7, position, "    O    ");
			wmvprintw(battleScreen, 8, position, "    O    ");
			wmvprintw(battleScreen, 9, position, "    O    ");
	}
}

BattleScene::~BattleScene()
{
	delete[] enemy;
}

