/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:34:50 by kchetty           #+#    #+#             */
/*   Updated: 2017/01/07 12:43:04 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

vector < vector <int> >  delimeter(board_class *copy)
{
	vector <vector <int> > co_ords;
	int x, y; 

	vector<int> temp;
	temp.push_back(0);
	temp.push_back(0);
	int tmp_y;
	int tmp_x;
	for (y = 0; y < 19; y++)
	{
		for (x = 0; x < 19; x++)
		{
			//tmp_x = x;
			//tmp_y = y;
			if ((copy->get(x + 1, y) == -1) && (copy->get(x, y) == 1 || copy->get(x, y) == 0) && (x + 1 < 19))
			{
				temp[0] = x + 1;
				temp[1] = y;
				co_ords.push_back(temp);
			}
			if ((copy->get(x, y + 1) == -1) && (copy->get(x, y) == 1 || copy->get(x, y) == 0) && (y + 1 < 19))
			{
				temp[0] = x;
				temp[1] = y + 1;
				co_ords.push_back(temp);
			}
			if ((copy->get(x, y - 1) == -1) && (copy->get(x, y) == 1 || copy->get(x, y) == 0) && (y - 1 >= 0))
			{
				temp[0] = x;
				temp[1] = y - 1;
				co_ords.push_back(temp);
			}
			if ((copy->get(x - 1, y) == -1) && (copy->get(x, y) == 1 || copy->get(x, y) == 0) && (x - 1 >= 0))
			{
				temp[0] = x - 1;
				temp[1] = y;
				co_ords.push_back(temp);
			}
			if ((copy->get(x + 1, y + 1) == -1) && (copy->get(x, y) == 1 || copy->get(x, y) == 0) && (y + 1 < 19 && x + 1 < 19))
			{
				temp[0] = x + 1;
				temp[1] = y + 1;
				co_ords.push_back(temp);
			}
			if ((copy->get(x + 1, y - 1) == -1) && (copy->get(x, y) == 1 || copy->get(x, y) == 0) && (y - 1 >= 0 && x + 1 < 19))
			{
				temp[0] = x + 1;
				temp[1] = y - 1;
				co_ords.push_back(temp);
			}
			if ((copy->get(x - 1, y - 1) == -1) && (copy->get(x, y) == 1 || copy->get(x, y) == 0) && (y - 1 >= 0 && x - 1 >= 0))
			{
				temp[0] = x - 1;
				temp[1] = y - 1;
				co_ords.push_back(temp);
			}
			if ((copy->get(x - 1, y + 1) == -1) && (copy->get(x, y) == 1 || copy->get(x, y) == 0) && (y + 1 < 19 && x - 1 >= 0))
			{
				temp[0] = x - 1;
				temp[1] = y + 1;
				co_ords.push_back(temp);
			}
		}
	}
	
	int flag = 0;
	vector < vector <int> > newer;
	for(unsigned int i = 0; i < co_ords.size(); i++)
	{
		tmp_x = co_ords[i][0];
		tmp_y = co_ords[i][1];
		for (unsigned int j = i + 1; j < co_ords.size(); j++)
		{
			if (tmp_x == co_ords[j][0] && tmp_y == co_ords[j][1])
				flag = 1;
		}
		if (flag == 0)
			newer.push_back(co_ords[i]);
		flag = 0;
	}

	return (newer);
}

void draw_screen(int dim, t_global *g)
{

	int x,y;
	int win_y, win_x;
	int tmp;


	getmaxyx(g->the_board, win_y, win_x);
	tmp = ((win_y / 2) - (38 / 2));
	//mvwprintw(g->the_board, 2, 2,  "teh x: %d AND WIN_Y: %d\n ", win_x  ,win_y);
	for(y = 0; y < dim; y++)
	{
		for(x = 0; x < dim; x++) 
		{
			if (x == 0)
			{
				//mvwprintw(g->the_board, tmp - 1, ((win_x / 2) - (79 / 2) + 1), "%d", y + 1);
				mvwprintw(g->the_board, tmp, ((win_x / 2) - (77 / 2)), " ---");
			}
			else
				wprintw(g->the_board, " ---");
		}
		wprintw(g->the_board, "\n");
		tmp++;
		for(x = 0; x < dim; x++)
		{
			if (x == 0)
			{
				//mvwprintw(g->the_board, tmp, ((win_x / 2) - (77 / 2)), "|   ");
				mvwprintw(g->the_board, tmp, ((win_x / 2) - (77 / 2)), "|   ");
			}
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
			mvwprintw(g->the_board, tmp , ((win_x / 2) - (77 / 2)), " ---");
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
	wmove(g->the_board, y*2+((win_y / 2) - (38 / 2)) + 1, x*4 + ((win_x / 2) - (77 / 2)) + 2);
	for (y = 0; y < 19; y++)
	{
		for (x = 0; x < 19; x++)
		{
			if (g->board->get(x, y) == 0)
			{
				init_color(COLOR_RED, 700,0, 700);
				init_pair(1, COLOR_RED, COLOR_BLACK);
				wattron(g->the_board, COLOR_PAIR(1));
				mvwprintw(g->the_board, y * 2 + ((win_y / 2) - (38 / 2)) + 1, x * 4 + ((win_x / 2) - (77 / 2)) + 2, "X");
				wattroff(g->the_board, COLOR_PAIR(1));
			}
			else if (g->board->get(x, y) == 1)
			{
				init_color(COLOR_CYAN, 700, 100, 0);
				init_pair(6, COLOR_CYAN, COLOR_BLACK);
				wattron(g->the_board, COLOR_PAIR(6));
				mvwprintw(g->the_board, y*2+ ((win_y / 2) - (38 / 2)) + 1, x*4+ ((win_x / 2) - (77 / 2)) + 2, "O");
				wattroff(g->the_board ,COLOR_PAIR(6));
			}
		}
	}
	wrefresh(g->the_board);
}

see bot(board_class* copy, int player)
{
	if (copy->check_win(0))
	{
		see testis;
		testis.value = 10;
		return testis;
	}
	if (copy->check_win(1))
	{
		see testis;
		testis.value = -10;
		return testis;
	}

	vector < vector <int> > test;
	vector < see > saves;
	test = delimeter(copy);


	copy->display();

	for (unsigned int j = 0; j < test.size(); j++)
	{
	  cout << test[j][0] << endl;
	  cout << test[j][1] << endl;
	  cout << endl;
	}

	sleep(14);
	for (unsigned int j = 0; j < test.size(); j++)
	{
		see hey;
		hey.x = test[j][0];
		hey.y = test[j][1];
		cout << hey.x << "   AND    " << hey.y << endl;
		sleep(2);
		if (player == 0)
			copy->set_x(test[j][0], test[j][1]);
		else
			copy->set_o(test[j][0], test[j][1]);
		//copy->display();	
		hey.value = bot(copy, !player).value;
		saves.push_back(hey);
		copy->new_set(test[j][0], test[j][1], -1);
	}

	int best_move = 0;
	if (player == 0)
	{
		int best_score = -100000;
		for (unsigned int o = 0; o < saves.size(); o++)
		{
			if (saves[o].value > best_score)
			{
				best_move = o;
				best_score = saves[o].value;
			}
		}	
	}
	else
	{
		int best_score = 100000;
		for (unsigned int o = 0; o > saves.size(); o++)
		{
			if (saves[o].value > best_score)
			{
				best_move = o;
				best_score = saves[o].value;
			}
		}	
	}
	return (saves[best_move]);
}

int  keyhook(int dim, int player, t_global *g, int val)
{
	int win_y, win_x;
	getmaxyx(g->the_board, win_y, win_x);
	//win_y -= win_y;
	mvwprintw(g->the_board, win_y, ((win_x / 2) - (23 / 2)), "Make you move: Player %c ",player==0 ? 'X' : 'O');
	wmove(g->the_board, g->y*2+((win_y / 2) - (38 / 2)) + 1, g->x*4 + ((win_x / 2) - (77 / 2)) + 2);
	wrefresh(g->the_board);
	noecho();

	if (val == 2 && player == 0)
	{
		board_class *copy;
		copy = new board_class();
		for (int yy = 0; yy < 19; yy++)
		{
			for (int xx = 0; xx < 19; xx++)
				copy->new_set(xx, yy, g->board->get(xx, yy));
		}
		see newt = bot(copy, player);
		cout << newt.x << " and " << newt.y << endl;
		g->board->set_x(newt.x, newt.y);
		echo();
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);                                  
		wattron(g->the_board, COLOR_PAIR(1));                                  
		mvwprintw(g->the_board, newt.y*2+((win_y / 2) - (38 / 2)) + 1,newt.x*4+ ((win_x / 2) - (77 / 2)) + 2, "X");
		wattroff(g->the_board, COLOR_PAIR(1));
		return (1);
	}
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
				/*if (val == 2)
				  {
				  board_class *copy;
				  copy = new board_class();
				  for (int yy = 0; yy < 19; yy++)
				  {
				  for (int xx = 0; xx < 19; xx++)
				  copy->new_set(xx, yy, g->board->get(xx, yy));
				  }
				//copy->display();
				bot(g, copy);
				return (1);
				}*/
				if (g->board->set_x(g->x, g->y) && val == 1)
				{
					//init_color(COLOR_RED, 700,0, 100);
					init_pair(1, COLOR_RED, COLOR_BLACK);
					wattron(g->the_board, COLOR_PAIR(1));
					mvwprintw(g->the_board, g->y*2+((win_y / 2) - (38 / 2)) + 1,g->x*4+ ((win_x / 2) - (77 / 2)) + 2, "X");
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
					//init_color(COLOR_CYAN, 700, 100, 0);
					init_pair(6, COLOR_CYAN, COLOR_BLACK);
					wattron(g->the_board, COLOR_PAIR(6));
					mvwprintw(g->the_board, g->y*2+((win_y / 2) - (38 / 2)) + 1,g->x*4+ ((win_x / 2) - (77 / 2)) + 2, "O");
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
	wmove(g->the_board, g->y*2+((win_y / 2) - (38 / 2)) + 1, g->x*4+((win_x - 80) / 2) + 2);
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
	g->board->init();

	initscr();
	noecho();
	cbreak();
}

void	draw_header(t_global *g)
{
	int win_y, win_x;

	start_color();
	init_pair(9, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	getmaxyx(g->header, win_y, win_x);

	wattron(g->header, COLOR_PAIR(9));
	mvwprintw(g->header,(win_y / 2) - 3, ((win_x / 2) - (52 / 2)), "# #     #   # ######### #   #            ##########\n");
	wattroff(g->header, COLOR_PAIR(9));

	wattron(g->header, COLOR_PAIR(4));
	mvwprintw(g->header,(win_y / 2) - 2, ((win_x / 2) - (52 / 2)), " #   #  #   #         # #   #   ######            #\n");
	wattroff(g->header, COLOR_PAIR(4));

	wattron(g->header, COLOR_PAIR(2));
	mvwprintw(g->header,(win_y / 2) - 1, ((win_x / 2) - (52 / 2)),  "# # #   #   #         # #   #        #           # \n");
	wattroff(g->header, COLOR_PAIR(2));	

	wattron(g->header, COLOR_PAIR(3));
	mvwprintw(g->header,(win_y / 2), ((win_x / 2) - (52 / 2)), "   #    #   # ########  #   #        #   ########  \n");
	wattroff(g->header, COLOR_PAIR(3));

	mvwprintw(g->header,(win_y / 2) + 1, ((win_x / 2) - (52 / 2)),  "  # #      #         #     #         #       ##    \n");

	wattron(g->header, COLOR_PAIR(5));
	mvwprintw(g->header,(win_y / 2) + 2, ((win_x / 2) - (52 / 2)), " #   #    #          #    #   ##########   ##      \n");
	wattroff(g->header, COLOR_PAIR(5));

	wattron(g->header, COLOR_PAIR(8));
	mvwprintw(g->header,(win_y / 2) + 3, ((win_x / 2) - (52 / 2)),  "      # ##    ########  ##               ##        \n");
	wattroff(g->header, COLOR_PAIR(8));

	wrefresh(g->header);
}

void	draw_player_stats(t_global *g, int player)
{
	int board_x;
	int board_y;

	getmaxyx(g->the_board, board_y, board_x);
	g->time = clock() - g->time;
	start_color();
	init_pair(10, COLOR_GREEN, COLOR_BLACK);
	if (!player)
		wattron(g->the_board, COLOR_PAIR(10));
	mvwprintw(g->the_board, board_y - 11, board_x - 25, "Player X\n");
	mvwprintw(g->the_board, board_y - 10, board_x - 25, "Captures %d\n", g->board->return_cap(0));
	mvwprintw(g->the_board, board_y - 9, board_x - 25, "time taken: %f\n", (((float)g->time)/CLOCKS_PER_SEC));
	wattroff(g->the_board, COLOR_PAIR(10));
	if (player)
		wattron(g->the_board, COLOR_PAIR(10));	
	mvwprintw(g->the_board, board_y - 13, board_x - 25, "Player O\n");	
	mvwprintw(g->the_board, board_y - 12, board_x - 25, "Captures %d\n", g->board->return_cap(1));
	wattroff(g->the_board, COLOR_PAIR(10));
	wrefresh(g->the_board);
}


int pvb(t_global *g)
{
	int dim,rtn,player = 1;
	int parent_x = 0, parent_y = 0, new_x, new_y;
	getmaxyx(stdscr, parent_y, parent_x);

	g->header = newwin(((parent_y / 4)), parent_x, 0, 0);
	g->the_board = newwin(parent_y - (parent_y / 4) + 1, parent_x, (parent_y / 4) - 1, 0);

	wclear(g->the_board);
	draw_borders(g->header);
	draw_borders(g->the_board);

	keypad(g->the_board,TRUE);
	dim = 19;

	draw_header(g);
	draw_screen(dim, g);
	redraw_stuff(g);
	draw_player_stats(g, player);
	g->time = clock();

	while (1)
	{
		getmaxyx(stdscr, new_y, new_x);
		if (new_y != parent_y || new_x != parent_x)
		{
			parent_x = new_x;
			parent_y = new_y;
			wresize(g->header, ((new_y / 4)), new_x);
			mvwin(g->header, 0, 0);
			wresize(g->the_board, new_y - (new_y / 4) + 1, new_x);
			mvwin(g->the_board, (new_y / 4) - 1, 0);
			wclear(stdscr);
			wclear(g->the_board);
			wclear(g->header);
			draw_borders(g->the_board);
			draw_borders(g->header);
			draw_header(g);
			draw_screen(dim, g);
			redraw_stuff(g);
		}
		if((rtn=keyhook(dim,player, g, 2))==-1)
			break;
		if (g->board->check_capture(player))
		{
			wclear(g->the_board);
			draw_screen(dim, g);
			redraw_stuff(g);
		}
		if(rtn == 1)
		{
			draw_player_stats(g, player);
			if (g->board->check_win(player) || g->board->return_cap(player) == 5)
			{
				g->board->init();
				break ;
			}
			player=!player;
			g->time = clock();
		}
		if (rtn == -3)
		{
			move(dim * 2 + 4, 0);
			printw("Invalid Move");
		}
	}
	delwin(g->the_board);
	delwin(g->header);
	endwin();


	printf("HAHAHAHAHA SOMEONE WON");
	return (0);
}


int pvp(t_global *g) 
{
	//t_global g;

	int dim,rtn,player = 0;
	int parent_x = 0, parent_y = 0, new_x, new_y;

	//get our maximun window dimensions
	getmaxyx(stdscr, parent_y, parent_x);

	g->header = newwin(((parent_y / 4)), parent_x, 0, 0);
	g->the_board = newwin(parent_y - (parent_y / 4) + 1, parent_x, (parent_y / 4) - 1, 0);

	wclear(g->the_board);
	draw_borders(g->header);
	draw_borders(g->the_board);

	keypad(g->the_board,TRUE);
	dim = 19; 

	draw_header(g);
	draw_screen(dim, g);
	redraw_stuff(g);
	draw_player_stats(g, player);
	g->time = clock();
	while (1)
	{
		getmaxyx(stdscr, new_y, new_x);
		if (new_y != parent_y || new_x != parent_x)
		{
			parent_x = new_x;
			parent_y = new_y;
			wresize(g->header, ((new_y / 4)), new_x);
			mvwin(g->header, 0, 0);
			wresize(g->the_board, new_y - (new_y / 4) + 1, new_x);
			mvwin(g->the_board, (new_y / 4) - 1, 0);
			wclear(stdscr);
			wclear(g->the_board);
			wclear(g->header);
			draw_borders(g->the_board);
			draw_borders(g->header);
			draw_header(g);
			draw_screen(dim, g);
			redraw_stuff(g);
		}
		if((rtn=keyhook(dim,player, g, 1))==-1)
			break;
		if (g->board->check_capture(player))
		{
			wclear(g->the_board);
			draw_screen(dim, g);
			redraw_stuff(g);
		}
		if(rtn == 1) 
		{
			draw_player_stats(g, player);
			if (g->board->check_win(player) || g->board->return_cap(player) == 5)
			{
				g->board->init();
				break ;
			}
			player=!player;
			g->time = clock();
		}
		if (rtn == -3)
		{
			move(dim * 2 + 4, 0);
			printw("Invalid Move");
		}
	}
	delwin(g->the_board);
	delwin(g->header);
	endwin();


	printf("HAHAHAHAHA SOMEONE WON");
	return (0);
}

void	credits_page()
{
	int x, y;
	getmaxyx(stdscr, y, x);

	WINDOW *win_credits = newwin(y, x, 0, 0);

	keypad(win_credits, true);

	while (1)
	{
		draw_borders(win_credits);
		wrefresh(win_credits);
		switch(wgetch(win_credits))
		{
			case 'q':
				{
					delwin(win_credits);
					endwin();
					return ;
				}
				break ;
		}
	}
}

void	help()
{
	int win_y = 0; 
	int win_x = 0;

	getmaxyx(stdscr, win_y, win_x);

	WINDOW *help_win = newwin(win_y, win_x, 0, 0);
	draw_borders(help_win);
	switch (wgetch(help_win))
	{
		case 'q':
			{
				delwin(help_win);
				endwin();
				return ;
			}
			break ;
	}		
}

int main()
{
	t_global g;

	int		win_x; //Max Win X
	int		win_y; //Max Win Y
	int		option = 1; //Current Selected Option
	int		c_x; //Center X of screen
	int		c_y; //Center Y of screen
	int		titleboxlen; //Strlen of titlebox
	titleboxlen = strlen("=========================================================================="); //Get Title Box Length To Center It


	init(&g);
	curs_set(FALSE);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);

	getmaxyx(stdscr, win_y, win_x); 

	WINDOW*win_menu = newwin(win_y, win_x, 0, 0);

	keypad(win_menu, true);

	while (1)
	{
		wclear(win_menu);
		getmaxyx(win_menu, win_y, win_x);
		c_x = win_x / 2; //Find Middle of X
		c_y = win_y / 2; //Find Middle of Y

		//Render Fancy Boxes ETC
		//The Text centering takes half the screen, then further subtracts half the strlen to center it perfectly. Just for you mister OCD

		if (win_y > 47 && win_x > 117)
		{
			mvwprintw(win_menu, 1, (c_x - (116 / 2)),  "      GGGGGGGGGGGGG                                                            kkkkkkkk                             \n");
			mvwprintw(win_menu, 2, (c_x - (116 / 2)),  "    GGG::::::::::::G                                                           k::::::k                             \n");  
			mvwprintw(win_menu, 3, (c_x - (116 / 2)),  "   GG:::::::::::::::G                                                          k::::::k                             \n");
			mvwprintw(win_menu, 4, (c_x - (116 / 2)),  "  G:::::GGGGGGGG::::G                                                          k::::::k                             \n");
			mvwprintw(win_menu, 5, (c_x - (116 / 2)),  " G:::::G       GGGGGG   ooooooooooo      mmmmmmm    mmmmmmm      ooooooooooo   k:::::k    kkkkkkkuuuuuu      uuuuuu \n");
			mvwprintw(win_menu, 6, (c_x - (116 / 2)),  "G:::::G               oo:::::::::::oo  mm:::::::m  m:::::::mm  oo:::::::::::oo k:::::k   k:::::k u::::u      u::::u \n"); 
			mvwprintw(win_menu, 7, (c_x - (116 / 2)),  "G:::::G              o:::::::::::::::om::::::::::mm::::::::::mo:::::::::::::::ok:::::k  k:::::k  u::::u      u::::u \n");
			mvwprintw(win_menu, 8, (c_x - (116 / 2)),  "G:::::G    GGGGGGGGGGo:::::ooooo:::::om::::::::::::::::::::::mo:::::ooooo:::::ok:::::k k:::::k   u::::u      u::::u \n");
			mvwprintw(win_menu, 9, (c_x - (116 / 2)),  "G:::::G    G::::::::Go::::o     o::::om:::::mmm::::::mmm:::::mo::::o     o::::ok::::::k:::::k    u::::u      u::::u \n");
			mvwprintw(win_menu, 10, (c_x - (116 / 2)), "G:::::G    GGGGG::::Go::::o     o::::om::::m   m::::m   m::::mo::::o     o::::ok:::::::::::k     u::::u      u::::u \n");
			mvwprintw(win_menu, 11, (c_x - (116 / 2)), "G:::::G        G::::Go::::o     o::::om::::m   m::::m   m::::mo::::o     o::::ok:::::::::::k     u::::u      u::::u \n");
			mvwprintw(win_menu, 12, (c_x - (116 / 2)), " G:::::G       G::::Go::::o     o::::om::::m   m::::m   m::::mo::::o     o::::ok::::::k:::::k    u::::::uuuu::::::u \n"); 
			mvwprintw(win_menu, 13, (c_x - (116 / 2)), "  G:::::GGGGGGGG::::Go:::::ooooo:::::om::::m   m::::m   m::::mo:::::ooooo:::::ok::::::k k:::::k  u:::::::::::::::uu \n");
			mvwprintw(win_menu, 14, (c_x - (116 / 2)), "   GG:::::::::::::::Go:::::::::::::::om::::m   m::::m   m::::mo:::::::::::::::ok::::::k  k:::::k  u:::::::::::::::u \n");
			mvwprintw(win_menu, 15, (c_x - (116 / 2)), "    GGG::::::GGG:::G oo:::::::::::oo  m::::m   m::::m   m::::m oo:::::::::::oo k::::::k   k:::::k  uu::::::::uu:::u \n");
			mvwprintw(win_menu, 16, (c_x - (116 / 2)), "       GGGGGG   GGGG   ooooooooooo    mmmmmm   mmmmmm   mmmmmm   ooooooooooo   kkkkkkkk    kkkkkkk  uuuuuuuu  uuuu  \n");
		}
		else
		{
			mvwprintw(win_menu, c_y - 10, c_x - (titleboxlen / 2), "==========================================================================");
			mvwprintw(win_menu, c_y - 9, c_x - (titleboxlen / 2), "||                                                                      ||");
			mvwprintw(win_menu, c_y - 8, c_x - (titleboxlen / 2), "||                                GOMOKU                                ||");
			mvwprintw(win_menu, c_y - 7, c_x - (titleboxlen / 2), "||                                                                      ||");
		}
		mvwprintw(win_menu, c_y - 6, c_x - (titleboxlen / 2), "==========================================================================");
		mvwprintw(win_menu, c_y - 5, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 4, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 3, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 2, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 1, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 1, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 2, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 3, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 4, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 5, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 6, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 7, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 8, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 9, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 10, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 11, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 12, c_x - (titleboxlen / 2), "==========================================================================");

		//Render Out Buttons, Inverse Video Of Selected
		if (option == 1)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y - 1, c_x - (strlen("Single Player") / 2), "Single Player");
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y - 1, c_x - (strlen("Single Player") / 2), "Single Player");

		if (option == 2)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y + 1, c_x - (strlen("MultiPlayer") / 2), "MultiPlayer");
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y + 1, c_x - (strlen("MultiPlayer") / 2), "MultiPlayer");

		if (option == 3)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y + 3, c_x - (strlen("Help") / 2), "Help");
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y + 3, c_x - (strlen("Help") / 2), "Help");

		if (option == 4)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y + 5, c_x - (strlen("Credits") / 2), "Credits");
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y + 5, c_x - (strlen("Credits") / 2), "Credits");

		if (option == 5)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y + 7, c_x - (strlen("Quit") / 2), "Quit");
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y + 7, c_x - (strlen("Quit") / 2), "Quit");

		//Update Screen
		wrefresh(win_menu);

		//Key Hooks
		switch(wgetch(win_menu))
		{
			case KEY_UP:
				if (option == 1)
					option = 5;
				else
					option -= 1;
				break;
			case KEY_DOWN:
				if (option == 5)
					option = 1;
				else
					option += 1;
				break;
			case 10: //10 Being Enter Key
				if (option == 1)
				{
					//Do One Player Stuff
					g.board->init();
					curs_set(TRUE);
					pvb(&g);
					curs_set(FALSE);
				}

				if (option == 2)
				{
					//Do Two Player Stuff
					g.board->init();
					curs_set(TRUE);
					pvp(&g);
					curs_set(FALSE);
				}

				if (option == 3)
				{
					//Help Stuff
					help();
				}

				if (option == 4)
				{
					//Credits Stuff
					credits_page();
				}

				if (option == 5)
				{
					//Quit The Game
					endwin();
					curs_set(TRUE);
					system("clear");
					return (0);
				}
				break;
		}
	}
}
