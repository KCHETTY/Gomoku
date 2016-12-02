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

int curX=0,curY=0;

void draw_screen(int dim)
{

	int x,y;

	for(y = 0; y < dim; y++)
	{
		for(x = 0; x < dim; x++) 
		{
			printw(" ---");
		}
		printw("\n");
		for(x = 0; x < dim; x++)
		{
			printw("|   ");
		}
		if(x == dim)
			printw("|\n");
		else
			printw("\n");	   	   	   	  
	}
	for(x = 0; x < dim; x++) 
	{
		printw(" ---");
	}
	printw("\n");
	refresh();
}

int  keyhook(int dim, int player, t_global *g)
{
	move(dim*2+2,0);
	printw("Player %c ",player==0 ? 'X' : 'O');
	move(curY*2+1,curX*4+2);
	refresh();
	noecho();
	switch(getch())
	{
		case KEY_UP:
			if(curY > 0)
				curY--;
			return(-2);
		case KEY_LEFT:
			if(curX > 0)
				curX--;
			return(-2);
		case KEY_RIGHT:
			if(curX < dim-1)
				curX++;
			return(-2);
		case KEY_DOWN:
			if(curY < dim-1)
				curY++;
			return(-2);
		case '\n':
			echo();
			refresh();
			start_color();
			if (player == 0)
			{
				if (g->board->set_x(curX, curY))
				{
					init_color(COLOR_RED, 700,0, 700);
					init_pair(1, COLOR_RED, COLOR_BLACK);
					attron(COLOR_PAIR(1));
					mvprintw(curY*2+1,curX*4+2, "X");
					attroff(COLOR_PAIR(1));
					return (1);
				}
				else
					return (-3);
			}
			else
			{
				if (g->board->set_o(curX, curY))
				{
					init_color(COLOR_CYAN, 700, 100, 0);
					init_pair(6, COLOR_CYAN, COLOR_BLACK);
					attron(COLOR_PAIR(6));
					mvprintw(curY*2+1,curX*4+2, "O");
					attroff(COLOR_PAIR(6));
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
	move(curY*2+2,curX*4+1);
	refresh();
	return(0);
}
int main() 
{
	t_global g;

	g.board = new board_class();
	int dim,rtn,player = 0;
	initscr();	
	keypad(stdscr,TRUE);
	cbreak();			

	dim = 19; 
	clear();
	draw_screen(dim);

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
	endwin();

	printf("HAHAHAHAHA SOMEONE WON");
	return (0);
}

/*int	main()
  {
  board_class *board = new board_class();
  int win = 1;
  int counter = 0;
  int x , y;

  board->display();


  while(win)
  {
  if (counter % 2 == 0)
  {
  cout << "player O" << endl;
  cout << "X" << endl;
  cin >> x;
  cout << "Y" << endl;
  cin >> y ;
  if (board->set_o(x, y))
  {
  counter++;
  board->display();
  }
  else
  cout << "invalid move" << endl;

  if (board->check_win(1))
  {
  cout << "PLAYER O WINS!!" << endl;
  break ;
  }
  }
  else
  {
  cout << "player X" << endl;
  cout << "X" << endl;
  cin >> x;
  cout << "Y" << endl;
  cin >> y;
  if (board->set_x(x, y))
  {
  counter--;
  board->display();
  }
  else
  cout << "invalid move" << endl;	

  if (board->check_win(2))
  {
  cout << "PLAYER X WINS!!" << endl;
  break ;
  }
  }

  }	

  return (0);
  }*/
