#include "terror.h"

void menumenu::wtitle(WINDOW *screen) //title function
{
	int buffer1=4;
	titlePlacement(58); //width, manually checked
	wmove(screen, buffer1+1, titleStartx); wprintw(screen,"··························································");
	wmove(screen, buffer1+2, titleStartx); wprintw(screen,": ____    ____      ___       ___       ____      ___    :");
	wmove(screen, buffer1+3, titleStartx); wprintw(screen,":/_  _|  F ___J    F _ ',    F _ ',    F __ ]    F _ ',  :");
	wmove(screen, buffer1+4, titleStartx); wprintw(screen,":[J  L] J |___:   J `-'(|   J `-'(|   J |--| L  J `-'(|  :");
	wmove(screen, buffer1+5, titleStartx); wprintw(screen,": |  |  | _____|  |  _  L   |  _  L   | |  | |  |  _  L  :");
	wmove(screen, buffer1+6, titleStartx); wprintw(screen,": F  J  F L____:  F |_|  L  F |_|  L  F L__J J  F |_|  L :");
	wmove(screen, buffer1+7, titleStartx); wprintw(screen,":J____LJ________LJ__| ||__LJ__| ||__LJ|______/FJ__| ||__L:");
	wmove(screen, buffer1+8, titleStartx); wprintw(screen,":|____||________||__|  J__||__|  J__| J______F |__|  J__|:");
	wmove(screen, buffer1+9, titleStartx); wprintw(screen,"··························································");
	
	/*
	empty space to paste-in a possible new title screen
	*/
}

void menumenu::skullart1()
{
	int buffer1=2;
	titlePlacement(80);
	 wmvprintw(mainscreen, buffer1+0, titleStartx, "                              █  ██████████████  █                              ");
	 wmvprintw(mainscreen, buffer1+1, titleStartx, "                          █ ████████████████████████ █                          ");
	 wmvprintw(mainscreen, buffer1+2, titleStartx, "                        ████████ ██          ██ ████████                        ");
	 wmvprintw(mainscreen, buffer1+3, titleStartx, "                      ██████ ██    █        █    ██ ██████                      ");
	 wmvprintw(mainscreen, buffer1+4, titleStartx, "	                 ███ ██ █      ██   ██   ██      █ ██ ███                    ");
	 wmvprintw(mainscreen, buffer1+5, titleStartx, "                  ██████   ██ █       █▒▒█       █ ██   ██████                  ");
	 wmvprintw(mainscreen, buffer1+6, titleStartx, "                 █ ██ █  █  █    █ ████  ████ █    █  █  █ ██ █                 ");
	 wmvprintw(mainscreen, buffer1+7, titleStartx, "                █▒██ ██ █ █                          █ █ ██ ██▒█                ");
	 wmvprintw(mainscreen, buffer1+8, titleStartx, "               █ ██ █ █▒█     █                  █     █▓█ █ ██ █               ");
	 wmvprintw(mainscreen, buffer1+9, titleStartx, "              █ ██   █ █                                █ █   ██ █              ");
	wmvprintw(mainscreen, buffer1+10, titleStartx, "             █ ██  ██               ███  ███               ██  ██ █             ");
	wmvprintw(mainscreen, buffer1+11, titleStartx, "             █ ████     █ ██ ██       █  █       ██ ██ █     ████ █             ");
	wmvprintw(mainscreen, buffer1+12, titleStartx, "              ██ ██   ███  █   ██              ██   █  ███   ██ ██              ");
	wmvprintw(mainscreen, buffer1+13, titleStartx, "              ██ █   ██ ███ ███  █   ██  ██   █  ███ ███ ██   █ ██              ");
	wmvprintw(mainscreen, buffer1+14, titleStartx, "             ██      █████      █ █          █ █      █████ ░    ██             ");
	wmvprintw(mainscreen, buffer1+15, titleStartx, "             ██      ██ ███  ██ ▓█            █▓ ██  ███ ██      ██             ");
	wmvprintw(mainscreen, buffer1+16, titleStartx, "             ██████   █  █   █ █ █            █ █ █   █  █   ██████             ");
	wmvprintw(mainscreen, buffer1+17, titleStartx, "               █ █ ████  █  █████  ▓  █  █  ▓  █████  █  ████ █ █               ");
	wmvprintw(mainscreen, buffer1+18, titleStartx, "               ██  █   ███████ ░     ██████     ░ ███████   █  ██               ");
	wmvprintw(mainscreen, buffer1+19, titleStartx, "                 ██ █    █          ██▒██▒██          █    █ ██                 ");
	wmvprintw(mainscreen, buffer1+20, titleStartx, "                 ███    █      ▒   ███ ██ ███   ▒      █    ███                 ");
	wmvprintw(mainscreen, buffer1+21, titleStartx, "                  ███▓         █  ██ ██  ██ ██  █         ▓███                  ");
	wmvprintw(mainscreen, buffer1+22, titleStartx, "                   █████ █  █      ▒█▓    ▓█▒      █  █ █████                   ");
	wmvprintw(mainscreen, buffer1+23, titleStartx, "                    █ ██     █                    █     ██ █                    ");
	wmvprintw(mainscreen, buffer1+24, titleStartx, "                      ████    █  ▓            █  █    ▓███                      ");
	wmvprintw(mainscreen, buffer1+25, titleStartx, "                     █████    █                  █    █████                     ");
	wmvprintw(mainscreen, buffer1+26, titleStartx, "                     █  ██ █                        █░██  █                     ");
	wmvprintw(mainscreen, buffer1+27, titleStartx, "                      █ █████    █ ████  ████ █    █████ █                      ");
	wmvprintw(mainscreen, buffer1+28, titleStartx, "                     ██ ███ ██████  ██ ██ ██  ██████ ███ ██                     ");
	wmvprintw(mainscreen, buffer1+29, titleStartx, "                    █ █  ████████ ████████████ ████████  █ █                    ");
	wmvprintw(mainscreen, buffer1+30, titleStartx, "                     ███ █ █  ██ ██ ████████ ██ ██  █ █ ███                     ");
	wmvprintw(mainscreen, buffer1+31, titleStartx, "                     ██ ████████ ██████████████ ████████ ██                     ");
	wmvprintw(mainscreen, buffer1+32, titleStartx, "                      █  ▒█████████████  █████████████▒  █                      ");
	wmvprintw(mainscreen, buffer1+33, titleStartx, "                      ██  ███ ████████    ████████ ███  ██                      ");
	wmvprintw(mainscreen, buffer1+34, titleStartx, "                      ██  ░   ███  █ ██████ █  ███   ░  ██                      ");
	wmvprintw(mainscreen, buffer1+35, titleStartx, "                       █  █                          █  █                       ");
	wmvprintw(mainscreen, buffer1+36, titleStartx, "                        ░█                            █▒                        ");
	wmvprintw(mainscreen, buffer1+37, titleStartx, "                       ██ █   █  █            █  █   █ ██                       ");
	wmvprintw(mainscreen, buffer1+38, titleStartx, "                         █ █ █        █  █        █ █ █                         ");
	wmvprintw(mainscreen, buffer1+39, titleStartx, "                           ███  █████ ████ █████  ███                           ");
	wmvprintw(mainscreen, buffer1+40, titleStartx, "                                   █ ██████ █                                   ");
}