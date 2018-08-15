#include<iostream>

using namespace std;

typedef struct hAw
{
	int x;
	int y;
	bool visit;
	hAw() {}
	hAw(int x, int y, bool visit) : x(x), y(y), visit(visit) {}

}hAw;

int game[10][10];
hAw zero[81];
bool height[10][10], width[10][10], ninetable[10][10];
int zerocnt = 0;
bool flag = false;
int getNine(int y, int x)
{
	return (y / 3) * 3 + x / 3;
}
void dfs(int cnt)
{
	if (flag)
		return;

	if (zerocnt == cnt) //모든 0이 채워졌으면 return 
	{
		flag = true;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << game[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}

	int x = zero[cnt].x;
	int y = zero[cnt].y;

	bool num[10] = { false, };
	for (int i = 1; i < 10; i++)
	{
		num[i] = true;
		if (height[y][i]) num[i] = false;
		if (width[x][i]) num[i] = false;
		if (ninetable[getNine(y, x)][i]) num[i] = false;
		if (num[i]) num[0] = false;
	}

	if (num[0]) return;

	for (int i = 1; i <= 9; i++)
	{
		if (num[i])
		{
			game[y][x] = i;
			height[y][game[y][x]] = width[x][game[y][x]] = ninetable[getNine(y, x)][game[y][x]] = true;
			dfs(cnt + 1);
			height[y][game[y][x]] = width[x][game[y][x]] = ninetable[getNine(y, x)][game[y][x]] = false;
			game[y][x] = 0;
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> game[i][j]; // 값이 0인 곳이 비어있는 곳
			if (game[i][j] == 0)
			{
				zero[zerocnt] = hAw(j, i, false);
				zerocnt++;
			}
			else // 0이 아닌 곳
			{
				height[i][game[i][j]] = true;
				width[j][game[i][j]] = true;
				ninetable[getNine(i, j)][game[i][j]] = true;
			}
		}
	}

	dfs(0);
}