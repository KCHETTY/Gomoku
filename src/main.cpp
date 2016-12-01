/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:34:50 by kchetty           #+#    #+#             */
/*   Updated: 2016/12/01 12:12:51 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int board[20][20];
int curX=0,curY=0;

void paintscreen(int dim)
{

	int x,y;
	for(y=0;y<dim;y++) {
		for(x=0;x<dim;x++) {
			printw(" ---");
		}
		printw("\n");
		for(x=0;x<dim;x++) {
			printw("|   ");
		}
		if(x==dim)
			printw("|\n");
		else
			printw("\n");	   	   	   	  
	}
	for(x=0;x<dim;x++) {
		printw(" ---");
	}
	printw("\n");
	refresh();
}

int put_in_cell(int dim, int x, int y, int num)
{
	if(x<0 || x>=dim || y<0 || y>=dim)
		return(1); 

	int cellx,celly;
	cellx=x*4+1;
	celly=y*2+2;
	mvprintw(celly,cellx,"%d",num);
	printw("%d %d\n",cellx,celly);
	refresh();
	return (0);
}

int  prompt(int dim, int player)
{
	int value;
	move(dim*2+2,0);
	printw("Player %c ",player==0 ? 'A' : 'B');
	move(curY*2+2,curX*4+1);
	refresh();
	noecho();
	switch(getch()) {
		case KEY_UP:
			if(curY>0)
				curY--;
			return(-2);
		case KEY_LEFT:
			if(curX>0)
				curX--;
			return(-2);
		case KEY_RIGHT:
			if(curX<dim-1)
				curX++;
			return(-2);
		case KEY_DOWN:
			if(curY<dim-1)
				curY++;
			return(-2);
		case '*':
			echo();
			cin >> value;
			if(value<=4 || value>=204) {
				mvprintw(curY*2+2,curX*4+1,"   ");
				refresh();
			}
			else {

				board[curX][curY]=value;
			}
			break;
		case 'q':
			return(-1); // Quit game
		default:
			return(-2); // Bad key
			break;
	}
	move(curY*2+2,curX*4+1);
	refresh();
	return(0);
}
int main() 
{
	int dim,rtn,player = 0;
	initscr();				// Start curses 
	keypad(stdscr,TRUE);	// Turn on keypad
	cbreak();				// Disable input buffering
	/*do {   
		printw("Please input a value between 4-20\n");
		cin >> dim;
		refresh();
	} while(dim<4 || dim>20);*/

	dim = 19; 
	clear();
	paintscreen(dim);

	while (1)
	{
		if((rtn=prompt(dim,player))==-1)
			break;
		if(rtn!=-2) { // Bad key or movement
			// Game logic here
			player=!player;
		}
	}
	endwin();
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
