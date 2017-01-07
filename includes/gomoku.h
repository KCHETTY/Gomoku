/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:35:01 by kchetty           #+#    #+#             */
/*   Updated: 2017/01/06 16:31:57 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GOMOKU_H_
# define _GOMOKU_H_

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <vector>
# include <ncurses.h>
# include <math.h>
# include <unistd.h>
# include <time.h>
# include <regex>
# include "board.class.h"
//# include "moves.class.h"

using namespace	std;

typedef struct		s_global
{
	clock_t			time;
	board_class		*board;
	WINDOW			*the_board;
	WINDOW			*header;
	int				x;
	int				y;
}					t_global;

struct see
{
	int x;
	int y; 
	int value;
};

#endif
