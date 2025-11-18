#include <iostream>
using namespace std;

/*
void control(int* pPos, int* mapType);
enum index
{
	X = 0,
	Y = 1,
};
const int startPPos[2] = { 4, 2 };
const int MAP_WIDTH = 9;
const int MAP_HEIGHT = 6;
int main()
{
	int pPos[] = { startPPos[X], startPPos[Y] };
	int mapType = 1;
	control(pPos, &mapType);
}

void control(int* pPos, int* mapType)
{
	char map = 1;
	char mapA[MAP_HEIGHT][MAP_WIDTH] =
	{
		{"########"},
		{"#      #"},
		{"# #    #"},
		{"# ###  #"},
		{"# W    #"},
		{"########"}
	};
	char mapB[MAP_HEIGHT][MAP_WIDTH] =
	{
		{"########"},
		{"#  #G  #"},
		{"#   #  #"},
		{"# #    #"},
		{"# W    #"},
		{"########"}
	};

	mapA[startPPos[Y]][startPPos[X]] = 'p';
	char (*currentMap)[MAP_WIDTH]; ;
	int gCount = 0;
	bool GOAL = false;
	bool WARP = false;
	while (true)
	{
		if (*mapType == 1) {
			currentMap = mapA;
		}
		else {
			currentMap = mapB;
		}

		gCount++;
		cout << gCount << "ƒ^[ƒ“–Ú" << endl;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << currentMap[i][j];
			}
			cout << endl;
		}
		if (GOAL)
		{
			cout << "GOAL!" << endl;
			return;
		}
		if (gCount > 15)
		{
			cout << "GAME OVER";
			return;
		}
		char input;
		cout << "WASD > " << flush;
		cin >> input;
		
		if (input == 'w')
		{
			if (currentMap[pPos[Y] - 1][pPos[X]] == '#')
			{
				continue;
			}
			else if (currentMap[pPos[Y] - 1][pPos[X]] == 'G')
			{
				GOAL = true;
			}
			else if (currentMap[pPos[Y] - 1][pPos[X]] == 'W')
			{
				currentMap[pPos[Y]][pPos[X]] = ' ';
				pPos[Y]--;
				if (*mapType == 1)
				{
					cout << "mapB" << endl;
					*mapType = 2;
					mapB[pPos[Y]][pPos[X]] = 'p';
				}
				else if (*mapType == 2)
				{
					cout << "mapA" << endl;
					*mapType = 1;
					mapA[pPos[Y]][pPos[X]] = 'p';
				}
				WARP = true;
				continue;
			}
			if (WARP)
			{
				currentMap[pPos[Y]][pPos[X]] = 'W';
				WARP = false;
			}
			else
			{
				currentMap[pPos[Y]][pPos[X]] = ' ';
			}
			currentMap[pPos[Y] - 1][pPos[X]] = 'p';
			pPos[Y]--;
		}
		if (input == 's')
		{
			if (currentMap[pPos[Y] + 1][pPos[X]] == '#')
			{
				continue;
			}
			else if (currentMap[pPos[Y] + 1][pPos[X]] == 'G')
			{
				GOAL = true;
			}
			else if (currentMap[pPos[Y] + 1][pPos[X]] == 'W')
			{
				currentMap[pPos[Y]][pPos[X]] = ' ';
				pPos[Y]++;
				if (*mapType == 1)
				{
					cout << "mapB" << endl;
					*mapType = 2;
					mapB[pPos[Y]][pPos[X]] = 'p';
				}
				else if (*mapType == 2)
				{
					cout << "mapA" << endl;
					*mapType = 1;
					mapA[pPos[Y]][pPos[X]] = 'p';
				}
				WARP = true;
				continue;
			}
			if (WARP)
			{
				currentMap[pPos[Y]][pPos[X]] = 'W';
				WARP = false;
			}
			else
			{
				currentMap[pPos[Y]][pPos[X]] = ' ';
			}
			currentMap[pPos[Y] + 1][pPos[X]] = 'p';
			pPos[Y]++;
		}
		if (input == 'a')
		{
			if (currentMap[pPos[Y]][pPos[X] - 1] == '#')
			{
				continue;
			}
			else if (currentMap[pPos[Y]][pPos[X] - 1] == 'G')
			{
				GOAL = true;
			}
			else if (currentMap[pPos[Y]][pPos[X] - 1] == 'W')
			{
				currentMap[pPos[Y]][pPos[X]] = ' ';
				pPos[X]--;
				if (*mapType == 1)
				{
					cout << "mapB" << endl;
					*mapType = 2;
					mapB[pPos[Y]][pPos[X]] = 'p';
				}
				else if (*mapType == 2)
				{
					cout << "mapA" << endl;
					*mapType = 1;
					mapA[pPos[Y]][pPos[X]] = 'p';
				}
				WARP = true;
				continue;
			}
			if (WARP)
			{
				currentMap[pPos[Y]][pPos[X]] = 'W';
				WARP = false;
			}
			else
			{
				currentMap[pPos[Y]][pPos[X]] = ' ';
			}
			currentMap[pPos[Y]][pPos[X] - 1] = 'p';
			pPos[X]--;
		}
		
		if (input == 'd')
		{
			if (currentMap[pPos[Y]][pPos[X] + 1] == '#')
			{
				continue;
			}
			else if (currentMap[pPos[Y]][pPos[X] + 1] == 'G')
			{
				GOAL = true;
			}
			else if (currentMap[pPos[Y]][pPos[X] + 1] == 'W')
			{
				currentMap[pPos[Y]][pPos[X]] = ' ';
				pPos[X]++;
				if (*mapType == 1)
				{
					cout << "mapB" << endl;
					*mapType = 2;
					mapB[pPos[Y]][pPos[X]] = 'p';
				}
				else if (*mapType == 2)
				{
					cout << "mapA" << endl;
					*mapType = 1;
					mapA[pPos[Y]][pPos[X]] = 'p';
				}
				WARP = true;
				continue;
			}
			if (WARP)
			{
				currentMap[pPos[Y]][pPos[X]] = 'W';
				WARP = false;
			}
			else
			{
				currentMap[pPos[Y]][pPos[X]] = ' ';
			}
			currentMap[pPos[Y]][pPos[X] + 1] = 'p';
			pPos[X]++;
		}
	}
}
*/