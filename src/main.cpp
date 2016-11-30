/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:34:50 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/30 08:29:37 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int	main()
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
				win = 0;
				cout << "PLAYER O WINS!!" << endl;
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
				 win = 0;
				 cout << "PLAYER X WINS!!" << endl;
			 }
		}

	}	

	return (0);
}
