/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:35:01 by kchetty           #+#    #+#             */
/*   Updated: 2016/12/01 13:45:24 by kchetty          ###   ########.fr       */
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
# include <regex>
# include "board.class.h"

using namespace std;

typedef struct s_global
{
	board_class *board;
}			   t_global;

#endif
