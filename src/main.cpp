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
	int tmp = 2;
	
//	wmove(g->the_board, 1, 4);
	for(y = 0; y < dim; y++)
	{
		for(x = 0; x < dim; x++) 
		{
			if (x == 0)
				mvwprintw(g->the_board, tmp, 8, " ---");
			else
				wprintw(g->the_board, " ---");
		}
		wprintw(g->the_board, "\n");
		tmp++;
		for(x = 0; x < dim; x++)
		{
			if (x == 0)
				mvwprintw(g->the_board, tmp, 8, "|   ");
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
			mvwprintw(g->the_board, tmp , 8, " ---");
		else
			wprintw(g->the_board, " ---");
	}
	wprintw(g->the_board, "\n");
	wrefresh(g->the_board);
}

int  keyhook(int dim, int player, t_global *g)
{
	//move(dim*2+2,0);
	//printw("Player %c ",player==0 ? 'X' : 'O');
	wmove(g->the_board, g->y*2+3,g->x*4+10);
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
					mvwprintw(g->the_board, g->y*2+3,g->x*4+10, "X");
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
					mvwprintw(g->the_board, g->y*2+3,g->x*4+10, "O");
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
	wmove(g->the_board, g->y*2+3,g->x*4+10);
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
	int parent_x = 0, parent_y = 0;
	
	init(&g);
	//get our maximun window dimensions
	getmaxyx(stdscr, parent_y, parent_x);

	g.header = newwin(parent_y - 44, parent_x, 0, 0);
	g.the_board = newwin(parent_y - 8, parent_x, 6, 0);

	draw_borders(g.header);
	draw_borders(g.the_board);
  
keypad(g.the_board,TRUE);
	dim = 19; 
	//clear();

	draw_screen(dim, &g);
	while (1)
	{
		if((rtn=keyhook(dim,player,&g))==-1)
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
	endwin();

	printf("HAHAHAHAHA SOMEONE WON");
	return (0);
}
