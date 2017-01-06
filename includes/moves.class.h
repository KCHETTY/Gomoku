/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.class.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:26:03 by kchetty           #+#    #+#             */
/*   Updated: 2017/01/06 16:36:19 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

using namespace std;

class moves
{
	private:
		int value
		int x;
		int y;

	public:

		void set_co_ords(int set_x, int set_y)
		{
			this->x = set_x;
			this->y = set_y;
		}

		void set_value(int val)
		{
			this->value = val;
		}
}

