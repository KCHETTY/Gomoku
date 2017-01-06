#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int array[19][19];
	int y, x;
	vector <vector <int> > co_ords;

	for (y = 0; y < 19; y++)
	{
		for (x = 0; x < 19; x++)
		{
			array[y][x] = -1;
		}
	}

	for (y = 0; y < 19; y++)
	{
		for (x = 0; x < 19; x++)
		{
			cout << array[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl << endl << endl;
	array[10][9] = 1;
	//array[10][11] = 2;
	//array[7][9] = 1;
	//array[11][13] = 2;

	for (y = 0; y < 19; y++)
	{   
		for (x = 0; x < 19; x++)
		{   
			cout << array[y][x] << " ";
		}   
		cout << endl;
	} 

	vector<int> temp;
	temp.push_back(0);
	temp.push_back(0);
	int tmp_y;
	int tmp_x;
	for (y = 0; y < 19; y++)
	{
		for (x = 0; x < 19; x++)
		{ 
			tmp_x = x;
			tmp_y = y;
			if (array[y][x + 1] == -1 && (array[y][x] == 1 || array[y][x] == 2) && (x + 1 < 19))
			{
				temp[0] = tmp_x += 1;
				temp[1] = y;
				tmp_x -= 1;
				co_ords.push_back(temp);
			}
			if (array[y + 1][x] == -1 && (array[y][x] == 1 || array[y][x] == 2) && (y + 1 < 19))
			{
				temp[0] = x;                                                 
				temp[1] = tmp_y += 1;
				tmp_y -= 1;
				co_ords.push_back(temp);
			}
			if (array[y - 1][x] == -1 && (array[y][x] == 1 || array[y][x] == 2) && (y - 1 >= 0))
			{
				temp[0] = x;                                                 
				temp[1] = tmp_y -= 1;
				tmp_y += 1;
				co_ords.push_back(temp);
			}
			if (array[y][x - 1] == -1 && (array[y][x] == 1 || array[y][x] == 2) && (x - 1 >= 0))
			{
				temp[0] = tmp_x -= 1;                                                 
				temp[1] = y;    
				tmp_x += 1;
				co_ords.push_back(temp);
			}
			if (array[y + 1][x + 1] == -1 && (array[y][x] == 1 || array[y][x] == 2) && (y + 1 < 19 && x + 1 < 19))
			{
				temp[0] = tmp_x += 1;                                                 
				temp[1] = tmp_y += 1;
				tmp_y -= 1;
				tmp_x -= 1;
				co_ords.push_back(temp);
			}
			if (array[y - 1][x + 1] == -1 && (array[y][x] == 1 || array[y][x] == 2) && (y - 1 >= 0 && x + 1 < 19))
			{
				temp[0] = tmp_x += 1;                                                 
				temp[1] = tmp_y -= 1;
				tmp_x -= 1;
				tmp_y += 1;
				co_ords.push_back(temp);
			}
			if (array[y - 1][x - 1] == -1 && (array[y][x] == 1 || array[y][x] == 2) && (y - 1 >= 0 && x - 1 >= 0))
			{
				temp[0] = tmp_x -= 1;                                                 
				temp[1] = tmp_y -= 1;
				tmp_x += 1;
				tmp_y += 1;
				co_ords.push_back(temp);
			}
			if (array[y + 1][x - 1] == -1 && (array[y][x] == 1 || array[y][x] == 2) && (y + 1 < 19 && x - 1 >= 0))
			{
				temp[0] = tmp_x -= 1;                                                 
				temp[1] = tmp_y += 1;
				tmp_y -= 1;
				tmp_x += 1;
				co_ords.push_back(temp);
			}
		}
	}
	cout << endl;
	for (int i = 0; i < co_ords.size(); i++)
	{
		cout << " " << co_ords[i][0] << endl;
		cout << " " << co_ords[i][1] << endl;
		cout << endl << endl;
	}


	return (0);
}

