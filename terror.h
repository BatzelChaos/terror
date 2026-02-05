#define MAIN_MENU 0
#define SETTINGS 1
#define CREDITS 2
#define EXIT 3
#define NEW_GAME 4

#define AUDIO 6
#define GRAPHICS 17
#define RESET 8
#define BACK 9
#define WINDOW_SIZE 18
#define COLOR_SELECT 19

void wmvprintw(WINDOW *screen, int y, int x, const char *text)

{
	wmove(screen, y, x);
	wprintw(screen, "%s", text);
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;
			
	local_win=newwin(height,width,starty,startx);
	wborder(local_win,'|','|','-','-','o','o','o','o');
	wrefresh(local_win);
			
	return local_win;
}
		
int random(int r)
{
	return rand()%r;
}