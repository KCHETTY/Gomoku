#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int array[19][19];
	int y, x;
	vector < vector <int> > co_ordinates[400, 0];

	for (y = 0; y < 19; y++)
	{
		for (x = 0; x < 19; x++)
		{
			array[y][x] = 0;
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
	array[11][11] = 1;
	array[10][11] = 2;
	array[7][9] = 1;
	array[11][13] = 2;

	for (y = 0; y < 19; y++)
	{   
		for (x = 0; x < 19; x++)
		{   
			cout << array[y][x] << " ";
		}   
		cout << endl;
	}  
		
	for (y = 0; y < 19; y++)
	{
		for (x = 0; x < 19; x++)
		{
			if (array[y][x + 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
				
			}
			if (array[y + 1][x] == -1 && array[y][x] == 1 || array[y][x] == 2)
			if (array[y - 1][x] == -1 && array[y][x] == 1 || array[y][x] == 2)
			if (array[y][x - 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			if (array[y + 1][x + 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			if (array[y - 1][x + 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			if (array[y - 1][x - 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			if (array[y + 1][x - 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
		}
	}

	return (0);
}

