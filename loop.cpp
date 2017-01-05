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
	
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(0);
	for (y = 0; y < 19; y++)
	{
		for (x = 0; x < 19; x++)
		{ 
			if (array[y][x + 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
					temp[0] = x + 1;
					temp[1] = y;
					co_ords.push_back(temp);
			}
			if (array[y + 1][x] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
					temp[0] = x;                                                 
			    temp[1] = y + 1;  
					co_ords.push_back(temp);
			}
			if (array[y - 1][x] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
					temp[0] = x;                                                 
			    temp[1] = y - 1;     
					co_ords.push_back(temp);
			}
			if (array[y][x - 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
					temp[0] = x - 1;                                                 
			    temp[1] = y;     
					co_ords.push_back(temp);
			}
			if (array[y + 1][x + 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
					temp[0] = x + 1;                                                 
			    temp[1] = y + 1;     
					co_ords.push_back(temp);
			}
			if (array[y - 1][x + 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
					temp[0] = x + 1;                                                 
			    temp[1] = y - 1;     
					co_ords.push_back(temp);
			}
			if (array[y - 1][x - 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
					temp[0] = x - 1;                                                 
			    temp[1] = y - 1;     
					co_ords.push_back(temp);
			}
			if (array[y + 1][x - 1] == -1 && array[y][x] == 1 || array[y][x] == 2)
			{
					temp[0] = x - 1;                                                 
			   	temp[1] = y + 1;     
					co_ords.push_back(temp);
			}
		}

		cout << endl;
		for (int i = 0; i < co_ords.size(); i++)
		{
				cout << " " << co_ords[i][0] << endl;	
				cout << " " << co_ords[i][1] << endl;
				cout << endl << endl;
		}

	}

	return (0);
}

