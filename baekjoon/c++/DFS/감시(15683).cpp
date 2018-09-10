#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Cctv
{
	int y;
	int x;
	int num;
	int choose;

public:
	Cctv() {}
	Cctv(int y, int x, int num, int choose) : y(y), x(x), num(num), choose(choose) {}

};

int N, M;
int map[10][10];
int tmp[10][10];
vector<Cctv> cctvList;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int minValue = 0;

//북,남,동,서
bool dirCk[6][4][4] = {
	{{false,false,false,false},{ false,false,false,false },{ false,false,false,false },{ false,false,false,false } },
{{true,false,false,false},{false,true,false,false},{false,false,true,false},{false,false,false,true}},//1
{{true,true,false,false},{false,false,true,true},},
{{true,false,true,false},{true,false,false,true},{false,true,true,false},{false,true,false,true}},
{{true,false,true,true},{false,true,true,true},{true,true,true,false},{true,true,false, true}},
{{true,true,true,true},}
};

int update(vector<Cctv> v) 
{
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			tmp[n][m] = map[n][m];
		}
	}


	for (int i = 0; i < v.size(); i++)
	{
		for (int d = 0; d < 4; d++)
		{
			if (dirCk[v[i].num][v[i].choose][d])
			{
				int ny = v[i].y;
				int nx = v[i].x;

				while (true)
				{
					ny += dir[d][0];
					nx += dir[d][1];

					if (ny >= 0 && nx >= 0 && ny < N && nx < M && map[ny][nx] != 6)
					{
						tmp[ny][nx] = -1;
					}
					else
						break;
				}
			}
		}
	}

	int ans = 0;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (tmp[n][m] == 0)
			{
				ans++;
			}
		}
	}

	return ans;
}


void Dfs(vector<Cctv> &v, int row)
{
	if (row > v.size())
		return;

	if (v.size() == cctvList.size())
	{
		minValue = min(minValue, update(v));
		return;
	}


	if (cctvList[row].num == 1)
	{
		for (int d = 0; d < 4; d++)
		{
			v.push_back(Cctv(cctvList[row].y, cctvList[row].x, cctvList[row].num, d));
			Dfs(v, row + 1);
			v.pop_back();
		}
	}
	else if (cctvList[row].num == 2)
	{
		for (int d = 0; d < 2; d++)
		{
			v.push_back(Cctv(cctvList[row].y, cctvList[row].x, cctvList[row].num, d));
			Dfs(v, row + 1);
			v.pop_back();
		}
	}
	else if (cctvList[row].num == 3)
	{
		for (int d = 0; d < 4; d++)
		{
			v.push_back(Cctv(cctvList[row].y, cctvList[row].x, cctvList[row].num, d));
			Dfs(v, row + 1);
			v.pop_back();
		}
	}
	else if (cctvList[row].num == 4)
	{
		for (int d = 0; d < 4; d++)
		{
			v.push_back(Cctv(cctvList[row].y, cctvList[row].x, cctvList[row].num, d));
			Dfs(v, row + 1);
			v.pop_back();
		}
	}
	else if (cctvList[row].num == 5)
	{
		v.push_back(Cctv(cctvList[row].y, cctvList[row].x, cctvList[row].num, 0));
		Dfs(v, row + 1);
		v.pop_back();
	}
		
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			cin >> map[n][m];

			if (map[n][m] == 0)
				minValue++;

			if(map[n][m] > 0 && map[n][m] != 6)
				cctvList.push_back(Cctv(n,m,map[n][m],0));
		}
	}

	vector<Cctv> v;
	Dfs(v,0);
	cout << minValue << "\n";

	return 0;
}