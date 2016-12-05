/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:34:50 by kchetty           #+#    #+#             */
/*   Updated: 2016/12/02 11:26:59 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

//int curX=0,curY=0;

void draw_screen(int dim, t_global *g)
{

	int x,y;
	int win_y, win_x;
	int tmp = 2;

		
	getmaxyx(g->the_board, win_y, win_x);
	mvwprintw(g->the_board, 1, 1,  "teh x: %d AND WIN_Y: %d\n ", win_x  ,win_y);
//	wmove(g->the_board, 1, 4);
	for(y = 0; y < dim; y++)
	{
		for(x = 0; x < dim; x++) 
		{
			if (x == 0)
				mvwprintw(g->the_board, tmp, ((win_x - 75) / 2), " ---");
			else
				wprintw(g->the_board, " ---");
		}
		wprintw(g->the_board, "\n");
		tmp++;
		for(x = 0; x < dim; x++)
		{
			if (x == 0)
				mvwprintw(g->the_board, tmp, ((win_x - 75) / 2), "|   ");
			else
				wprintw(g->the_board, "|   ");
		}
		tmp++;
		if(x == dim)
			wprintw(g->the_board, "|\n");
		else
			wprintw(g->the_board, "\n");	   	   	   	  
	}
	for(x = 0; x < dim; x++) 
	{
		if (x == 0)
			mvwprintw(g->the_board, tmp , ((win_x - 75) / 2), " ---");
		else
			wprintw(g->the_board, " ---");
	}
	wprintw(g->the_board, "\n");
	wrefresh(g->the_board);
}

void	redraw_stuff(t_global *g)
{
		int y = 0, x = 0;
		int win_y, win_x;
  	getmaxyx(g->the_board, win_y, win_x);
		start_color();
  	win_y -= win_y;	
		wmove(g->the_board, y*2+3,x*4 + ((win_x - 75) / 2) + 2);
		for (y = 0; y < 19; y++)
		{
				for (x = 0; x < 19; x++)
				{
						if (g->board->get(x, y) == 0)
						{
								init_color(COLOR_RED, 700,0, 700);
          			init_pair(1, COLOR_RED, COLOR_BLACK);
          			wattron(g->the_board, COLOR_PAIR(1));
          			mvwprintw(g->the_board, y*2+3,x*4+ ((win_x - 75) / 2) + 2, "X");
          			wattroff(g->the_board, COLOR_PAIR(1));
						}
						else if (g->board->get(x, y) == 1)
						{
								init_color(COLOR_CYAN, 700, 100, 0);
          			init_pair(6, COLOR_CYAN, COLOR_BLACK);
          			wattron(g->the_board, COLOR_PAIR(6));
         		 		mvwprintw(g->the_board, y*2+3,x*4+((win_x - 75) / 2) + 2, "O");
          			wattroff(g->the_board ,COLOR_PAIR(6));
						}
				}
		}
		wrefresh(g->the_board);
}	

int  keyhook(int dim, int player, t_global *g)
{
	//move(dim*2+2,0);
	int win_y, win_x;
	getmaxyx(g->the_board, win_y, win_x);
	win_y -= win_y;
	mvwprintw(g->the_board, dim * 2 + 4, 2, "Make you move: Player %c ",player==0 ? 'X' : 'O');
	wmove(g->the_board, g->y*2+3,g->x*4 + ((win_x - 75) / 2) + 2);
	wrefresh(g->the_board);
	noecho();
	switch(wgetch(g->the_board))
	{
		case KEY_UP:
			if(g->y > 0)
				g->y--;
			return(-2);
		case KEY_LEFT:
			if(g->x > 0)
				g->x--;
			return(-2);
		case KEY_RIGHT:
			if(g->x < dim-1)
				g->x++;
			return(-2);
		case KEY_DOWN:
			if(g->y < dim-1)
				g->y++;
			return(-2);
		case '\n':
			echo();
			wrefresh(g->the_board);
			start_color();
			if (player == 0)
			{
				if (g->board->set_x(g->x, g->y))
				{
					init_color(COLOR_RED, 700,0, 700);
					init_pair(1, COLOR_RED, COLOR_BLACK);
					wattron(g->the_board, COLOR_PAIR(1));
					mvwprintw(g->the_board, g->y*2+3,g->x*4+ ((win_x - 75) / 2) + 2, "X");
					wattroff(g->the_board, COLOR_PAIR(1));
					return (1);
				}
				else
					return (-3);
			}
			else
			{
				if (g->board->set_o(g->x, g->y))
				{
					init_color(COLOR_CYAN, 700, 100, 0);
					init_pair(6, COLOR_CYAN, COLOR_BLACK);
					wattron(g->the_board, COLOR_PAIR(6));
					mvwprintw(g->the_board, g->y*2+3,g->x*4+((win_x - 75) / 2) + 2, "O");
					wattroff(g->the_board ,COLOR_PAIR(6));
					return (1);
				}
				else
					return (-3);
			}
			break;
		case 'q':
			return(-1);
		default:
			return(-2);
			break;
	}
	wmove(g->the_board, g->y*2+3,g->x*4+((win_x - 75) / 2) + 2);
	wrefresh(g->the_board);
	return(0);
}

void draw_borders(WINDOW *screen) 
{ 
	int x, y, i; 
	getmaxyx(screen, y, x); 
	
	// 4 corners 
	mvwprintw(screen, 0, 0, "+"); 
	mvwprintw(screen, y - 1, 0, "+"); 
	mvwprintw(screen, 0, x - 1, "+"); 
	mvwprintw(screen, y - 1, x - 1, "+"); 
	
	// sides 
	for (i = 1; i < (y - 1); i++) 
	{ 
			mvwprintw(screen, i, 0, "|"); 
			mvwprintw(screen, i, x - 1, "|"); 
	} 

	// top and bottom 
	for (i = 1; i < (x - 1); i++) 
	{ 
			mvwprintw(screen, 0, i, "-"); 
			mvwprintw(screen, y - 1, i, "-"); 
	}

	wrefresh(screen); 
}

void	create_menu()
{
		int max_x, max_y;
		
		getmaxyx(stdscr, max_y, max_x);
		WINDOW *menu = newwin(max_y, max_x, 0, 0);
		
		start_color();
		draw_borders(menu);
		//init_pair(6, COLOR_CYAN, COLOR_BLACK, COLOR_);
    wattron(menu, COLOR_PAIR(6));
 		mvwprintw(menu,1, 17, "    _____\n");
		wattroff(menu, COLOR_PAIR(6));
    //wattron(menu, COLOR_PAIR(6));
		mvwprintw(menu,2, 17, " __|___  |__  _____  ____    __  _____  __  __  __   _\n");
		mvwprintw(menu,3, 17, "|   ___|    |/     \\|    \\  /  |/     \\|  |/ / |  | | |\n");
		mvwprintw(menu,4, 17, "|   |  |    ||     ||     \\/   ||     ||     \\ |  |_| |\n");
		mvwprintw(menu,5, 17, "|______|  __|\\_____/|__/\\__/|__|\\_____/|__|\\__\\|______|\n");
		mvwprintw(menu,6, 17, "  |_____|\n");
		//mvwprintw(menu,6, 13,	"!!! !!&!!  !&!  !!!  !&!   ! !&!  !&!  !!!  !!&!!!    !&!  !!!\n");
		//mvwprintw(menu,7,	13,":!!   !!:  !!:  !!!  !!:     !!:  !!:  !!!  !!: :!!   !!:  !!!\n");
		//mvwprintw(menu,8,	13, ":!:   !::  :!:  !:!  :!:     :!:  :!:  !:!  :!:  !:!  :!:  !:!\n");
		//mvwprintw(menu,9,	13, ":::  ::::  ::::: ::  :::     ::   ::::: ::   ::  :::  ::::: ::\n");
		//mvwprintw(menu,10, 13, " :: :: :    : :  :    :      :     : :  :    :   :::   : :  :\n");
		
		while (1)	
			wrefresh(menu);
}

void	init(t_global *g)
{
	g->x = 0;
  g->y = 0;
  g->board = new board_class();

	initscr();
	noecho();
  cbreak();
}

int main() 
{
	t_global g;

	int dim,rtn,player = 0;
	int parent_x = 0, parent_y = 0, new_x, new_y;
	
	init(&g);

	create_menu();
	//get our maximun window dimensions
	getmaxyx(stdscr, parent_y, parent_x);

	g.header = newwin(parent_y - 44, parent_x, 0, 0);
	g.the_board = newwin(parent_y - 7, parent_x, 7, 0);

	draw_borders(g.header);
	draw_borders(g.the_board);
  
keypad(g.the_board,TRUE);
	dim = 19; 
	//clear();

	draw_screen(dim, &g);
	while (1)
	{
		getmaxyx(stdscr, new_y, new_x);
    if (new_y != parent_y || new_x != parent_x)
		{
       	parent_x = new_x;
        parent_y = new_y;
        wresize(g.header, new_y - 44, new_x);
        wresize(g.the_board, new_y - 7, new_x);
       	mvwin(g.the_board, new_y - 7, 0);
        wclear(stdscr);
        wclear(g.the_board);
        wclear(g.header);
				draw_screen(dim, &g);
        draw_borders(g.the_board);
        draw_borders(g.header);
				redraw_stuff(&g);
    }
		if((rtn=keyhook(dim,player, &g))==-1)
			break;
		if(rtn == 1) {
			if (g.board->check_win(player))
				break ;
			player=!player;
		}
		if (rtn == -3)
		{
			move(dim * 2 + 4, 0);
			printw("Invalid Move");
		}
	}
	delwin(g.the_board);
	delwin(g.header);
	endwin();

	printf("HAHAHAHAHA SOMEONE WON");
	return (0);
}
