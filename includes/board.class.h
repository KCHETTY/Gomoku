/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.class.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:49:26 by kchetty           #+#    #+#             */
/*   Updated: 2016/12/10 11:24:34 by kchetty          ###   ########.fr       */
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
		int capture_o;
		int capture_x;

	public:

		void init(void)
		{
			for (int y = 0; y < 19; y++)
			{
				for (int x = 0; x < 19; x++)
					this->board[y][x] = -1;
			}

			this->capture_o = 0;
			this->capture_x = 0;
		};

		int	get(int x, int y) { return (this->board[y][x]); }
		int set_x(int x, int y) 
		{ 
			if ((this->board[y][x] == -1) && (x >= 0 && x <= 19) && (y >= 0 && y <= 19))
			{
				this->board[y][x] = 0;
				return (1);
			}
			return (0);
		}
		int set_o(int x, int y) 
		{ 
			if ((this->board[y][x] == -1) && (x >= 0 && x <= 19) && (y >= 0 && y <= 19    ))
			{
				this->board[y][x] = 1; 
				return (1);
			}
			return (0);
		}
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
						for (int checks = 0; checks < 4; checks++)
						{
							if (count != 5)
							{
								count = 0;
								tmp_x = x;
								tmp_y = y;
								for (int run = 0; run < 5; run++)
								{
									/*if (checks == 0)
									  {
									  if (this->board[tmp_y][tmp_x] == player && tmp_x - 1 != -1)
									  {
									  count++;
									  tmp_x -= 1;
									  }
									  }*/
									if (checks == 0)
									{
										if (this->board[tmp_y][tmp_x] == player && tmp_x + 1 != 20)
										{
											count++;
											tmp_x += 1;
										}
									}
									/*if (checks == 2)
									  {
									  if (this->board[tmp_y][tmp_x] == player && tmp_y - 1 != -1)
									  {
									  count++;
									  tmp_y -= 1;
									  }
									  }*/
									if (checks == 1)
									{
										if (this->board[tmp_y][tmp_x] == player && tmp_y + 1 != 20)
										{
											count++;
											tmp_y += 1;
										}
									}

									if (checks == 2)
									{
										if (this->board[tmp_y][tmp_x] == player && tmp_x + 1 != 20 && tmp_y + 1!= 20)
										{
											count++;
											tmp_y += 1;
											tmp_x += 1;
										}
									}
									if (checks == 3)
									{
										if (this->board[tmp_y][tmp_x] == player && tmp_x - 1 != -1 && tmp_y + 1!= 20)
										{
											count++;
											tmp_x -= 1;
											tmp_y += 1;
										}
									}
									/*if (checks == 6)
									  {
									  if (this->board[tmp_y][tmp_x] == player && tmp_x + 1 != 20 && tmp_y - 1!= -1)
									  {
									  count++;
									  tmp_x += 1;
									  tmp_y -= 1;
									  }
									  }*/
									/*if (checks == 7)
									  {
									  if (this->board[tmp_y][tmp_x] == player && tmp_x - 1 != -1 && tmp_y -1 != -1)
									  {
									  count++;
									  tmp_x -= 1;
									  tmp_y -= 1;
									  }
									  }*/
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

		int return_cap(int player) 
		{
			if (player)
				return (this->capture_o);
			return (this->capture_x);
		}		

		int check_capture(int player)
		{
				int tmp_y = 0;
				int tmp_x = 0;
				int count = 0;
				for (int y = 0; y < 19; y++)
				{
					 for (int x = 0; x < 19; x++)
					 {
							if (this->board[y][x] == player)
							{
								 tmp_y = y;
								 tmp_x = x;
								 for (int check = 0; check <= 4; check++)
								 {
										if (count != 2)
										{
											 count = 0;
											 for (int run = 0; run < 2; run++)
											 {
													if (check == 0 && this->board[tmp_y][tmp_x + 1] == !player && tmp_x + 1 != 20)
													{
															count += 1;
															tmp_x += 1;
													}
													else if (check == 1 && this->board[tmp_y + 1][tmp_x + 1] == !player && tmp_x + 1 != 20 && tmp_y + 1 != 20)
                          {
                              count += 1;
                              tmp_x += 1;
															tmp_y += 1;
                          }
													else if (check == 2 && this->board[tmp_y + 1][tmp_x] == !player && tmp_y + 1 != 20)
                          {
                              count += 1;
                              tmp_y += 1;
                          }
													else if (check == 3 && this->board[tmp_y + 1][tmp_x - 1] == !player && tmp_x - 1 != -1 && tmp_y + 1 != 20)
                          {
                              count += 1;
                              tmp_x -= 1;
															tmp_y += 1;
                          }
											 }
										}
										else
										{
											 //if (tmp_y + 1 != 20 && tmp_x - 1 != -1 && tmp_x + 1 != 20)
											 //{
													if (check - 1 == 0 && this->board[tmp_y][tmp_x + 1] == player)
                          {
                              this->board[tmp_y][tmp_x] = -1;
															this->board[tmp_y][tmp_x -1] = -1;
															if (player)
																capture_o += 1;
															else
																capture_x += 1;
                              return (1);
                          }
													else if (check - 1 == 1 && this->board[tmp_y + 1][tmp_x + 1] == player)
                          {
                              this->board[tmp_y][tmp_x] = -1;
                              this->board[tmp_y - 1][tmp_x -1] = -1;
															if (player)
                                capture_o += 1;
                              else
                                capture_x += 1;
                              return (1);
                          }
													else if (check - 1 == 2 && this->board[tmp_y + 1][tmp_x] == player)
                          {
                              this->board[tmp_y][tmp_x] = -1;
                              this->board[tmp_y - 1][tmp_x] = -1;
															if (player)
                                capture_o += 1;
                              else
                                capture_x += 1;
                              return (1);
                          }
													else if (check - 1 == 3 && this->board[tmp_y + 1][tmp_x - 1] == player)
                          {
                              this->board[tmp_y][tmp_x] = -1;
                              this->board[tmp_y - 1][tmp_x + 1] = -1;
															if (player)
                                capture_o += 1;
                              else
                                capture_x += 1;
                              return (1);
                          }
											// }
											 count = 0;
										}
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
