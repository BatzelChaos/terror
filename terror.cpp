#include <iostream>
#include <fstream>
#include <termios.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "batz.h"

/*
0=main menu
1=setttings
*/

void title()
{
  mvprintw(0,0,"··························································");
	mvprintw(1,0,": ____    ____      ___       ___       ____      ___    :");
	mvprintw(2,0,":/_  _|  F ___J    F _ ',    F _ ',    F __ ]    F _ ',  :");
	mvprintw(3,0,":[J  L] J |___:   J `-'(|   J `-'(|   J |--| L  J `-'(|  :");
	mvprintw(4,0,": |  |  | _____|  |  _  L   |  _  L   | |  | |  |  _  L  :");
	mvprintw(5,0,": F  J  F L____:  F |_|  L  F |_|  L  F L__J J  F |_|  L :");
	mvprintw(6,0,":J____LJ________LJ__| ||__LJ__| ||__LJ|______/FJ__| ||__L:");
	mvprintw(7,0,":|____||________||__|  J__||__|  J__| J______F |__|  J__|:");
	mvprintw(8,0,"··························································");
}



void settings(int menu)
{
  mvprintw(9,0,"\n\n> Audio\n  Graphics\n  Reset to default options\n  Save");
  switch(menu)
  {
    case 0:
      mvprintw(9,0,"\n\n> Audio\n  Graphics\n  Reset to default options\n  Save");
      break;
    case 1: 
      mvprintw(9,0,"\n\n  Audio\n> Graphics\n  Reset to default options\n  Save");
      break;
    case 2: 
      mvprintw(9,0,"\n\n  Audio\n  Graphics\n> Reset to default options\n  Save");
      break;
    case 3: 
      mvprintw(9,0,"\n\n  Audio\n  Graphics\n  Reset to default options\n> Save");
      break;
  }	    
}

void play()
{
    printw("wowsers it works");
    getch();
}

void credits(int menu)
{
  
}

void exitProgram()
{
  endwin();
}

int mainMenu(int menu, bool enterpressed)
{
	mvprintw(9,0,"\n\n> Play\n  Settings\n  Credits\n  Exit");
	switch(menu)
  {
		  case 0: 
		    mvprintw(9,0,"\n\n> Play\n  Settings\n  Credits\n  Exit");
        if (enterpressed==true) return 4; 
  		  refresh();
  		  break;
  		case 1: 
  		  mvprintw(9,0,"\n\n  Play\n> Settings\n  Credits\n  Exit");
        if (enterpressed==true) return 1; 
  		  refresh();
  		  break;
  		case 2: 
  		  mvprintw(9,0,"\n\n  Play\n  Settings\n> Credits\n  Exit");
        if (enterpressed==true) return 2; 
  		  refresh();
  		  break;
  		case 3: 
  		  mvprintw(9,0,"\n\n  Play\n  Settings\n  Credits\n> Exit");
        if (enterpressed==true) return 3; 
  		  refresh();
  		  break;
  } 
  return 0;
}

int mainMenuMove(int menuType, bool gamerunning)
{
  int keypressed;
  bool inloop=true;
  int menu;
  while(inloop==true)
	{
	keypressed=getch();
		switch(keypressed)
		{
		  case KEY_UP:
		    menu--;
		    if(menu<=0) menu=0;
        break;
      case KEY_DOWN:
        menu++;
	      if(menu>=3) menu=3;
		    break;
		  case 10: //KEY_ENTER
		    switch(menuType)
		    {
		      case 0:
		        inloop=false;
		        menuType=mainMenu(menu, true);
		        return menuType;
	          break;
	         case 1: 
	          inloop=false;
		        return menuType;
		        break;
		      case 2:
		        inloop=false;
		        return menuType;
		        break;
	        case 3: 
	          inloop=false;
		        return menuType;
		        break;
		      case 4:
		        inloop=false;
		        gamerunning=true;
		        return menuType;
		    }
		    break;
		  default: break;
		}
    switch(menuType)
		{
      case 0:
        mainMenu(menu, false);
        break;
      case 1: 
        settings(menu);
        break;
      case 2: 
        credits(menu);
        break;
      case 3: 
        exitProgram();
        break;
    }
	}
	return 0;
}

void menuInitialise(int menuType)
{
  title();
  mainMenu(0, false);
  
  bool gamerunning=false;
  while(gamerunning==false)
  {
    mainMenuMove(menuType, gamerunning);
  }
  play();
}

int main()
{
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  
  menuInitialise(0);
  
  getch();
  endwin();
  
  return 0;
}