#include<iostream>

using namespace std;

int map[9][9];
int main(void)
{
	int maxValue = -1;
	int y, x;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (maxValue < map[i][j])
			{
				maxValue = map[i][j];
				y = i;
				x = j;
			}
		}
	}

	cout << maxValue << endl;
	cout << y+1 << " " << x+1 << endl;
	return 0;
}