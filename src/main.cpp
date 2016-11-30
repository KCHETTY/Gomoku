/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:34:50 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/29 14:32:54 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int	main()
{
	board_class *test = new board_class();
	

	test->display();

	test->set_x(5, 5);
	test->set_x(4, 4);
 	test->set_x(3, 3);
 	test->set_x(1, 1);
 	test->set_x(0, 0);
	test->set_o(6, 5); 
  test->set_o(7, 3); 
  test->set_o(3, 7); 
  test->set_o(4, 5); 
  test->set_o(0, 3);

	cout << endl << endl;
	test->display();

	cout << endl;
	if (test->check_win(1))
		cout << "YOU WIN" << endl;
	else
		cout << "YOU LOSE" << endl;
	

	return (0);
}
