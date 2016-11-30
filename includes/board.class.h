/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.class.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:49:26 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/29 14:32:56 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

using namespace std;

class board_class
{
	private:
		int	board[19][19];
	
	public:
		
		board_class(void)
		{
			for (int y = 0; y < 19; y++)
			{
				for (int x = 0; x < 19; x++)
					this->board[y][x] = 0;
			}
		};

		int	get(int x, int y) { return (this->board[y][x]); }
		void set_x(int x, int y) { this->board[y][x] = 1; }
		void set_o(int x, int y) { this->board[y][x] = 2; }
		void display(void) 
		{
				for (int y = 0; y < 19; y++)
      	{
        		for (int x = 0; x < 19; x++)
          		cout << this->board[y][x] << " ";
						cout << endl;
      	}

		}

		int check_win(int player)
		{
			 int tmp_x = 0;
				int tmp_y = 0;
				int count = 0;

			 for (int y = 0; y < 19; y++)
			 {
					for (int x = 0; x < 19; x++)
					{
						if (this->board[y][x] == player)
						{
						 	for (int checks = 0; checks < 8; checks++)
						 	{
									if (count != 5)
									{
										count = 0;
										tmp_x = x;
										tmp_y = y;
										for (int run = 0; run < 5; run++)
										{
												if (checks == 0)
												{
											 		if (this->board[tmp_y][tmp_x] == player && tmp_x - 1 != -1)
											 		{
															count++;
															tmp_x -= 1;
											 		}
												}
											 	if (checks == 1)
                      	{
                        	if (this->board[tmp_y][tmp_x] == player && tmp_x + 1 != 20)
                        	{
                           	 count++;
                            	tmp_x += 1;
                        	}
                      	}
											 	if (checks == 2)
                      	{
                        	if (this->board[tmp_y][tmp_x] == player && tmp_y - 1 != -1)
                        	{
                           	 count++;
                            	tmp_y -= 1;
                        	}
                      	}
											 	if (checks == 3)
                      	{
                        	if (this->board[tmp_y][tmp_x] == player && tmp_y + 1 != 20)
                        	{
                          	  count++;
                            	tmp_x += 1;
                        	}
                      	}

											 	if (checks == 4)
                      	{
                        	if (this->board[tmp_y][tmp_x] == player && tmp_x + 1 != 20 && tmp_y + 1!= 20)
                        	{
                          	  count++;
                            	tmp_y += 1;
															tmp_x += 1;
                        	}
                      	}
											 	if (checks == 5)
                      	{
                        	if (this->board[tmp_y][tmp_x] == player && tmp_x - 1 != -1 && tmp_y + 1!= 20)
                        	{
                          	  count++;
                           	  tmp_x -= 1;
															tmp_y += 1;
                        	}
                      	}
											 	if (checks == 6)
                      	{
                        	if (this->board[tmp_y][tmp_x] == player && tmp_x + 1 != 20 && tmp_y - 1!= -1)
                        	{
                           	  count++;
                            	tmp_x += 1;
															tmp_y -= 1;
                       	 }
                      	}
											 	if (checks == 7)
                      	{
                        	if (this->board[tmp_y][tmp_x] == player && tmp_x - 1 != -1 && tmp_y -1 != -1)
                        	{
                           	 count++;
                           	 tmp_x -= 1;
															tmp_y -= 1;
                        	}
                      	}
									}
								}
								else
									return (1);
								}
						 }
					}
			 }
			return (0);
		}

		/*int check_move(int x, int y)
		{
				if (this->board[y][x] == 0)
				{
						if ()	
				}
				return (0);
		}*/
};
