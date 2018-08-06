#include<iostream>
#include<vector>
using namespace std;

typedef struct Cloud 
{
	vector<pair<int, int>> v;
public:
	Cloud() {}
	Cloud(vector<pair<int, int>> &v) : v(v) {}
};

int N = -1;
int map[366][4][4];
int rain[4][4];
int dir[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };
int ans = false;
Cloud c;

void Print()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bool ck = false;
			for (int m = 0; m < c.v.size(); m++)
			{
				if (i == c.v[m].first && j == c.v[m].second)
				{
					cout << "■";
					ck = true;
					break;
				}
			}

			if (!ck)
				cout << "□";
		}
		cout << endl;
	}

}


void Dfs(int day, int r[4][4])
{
	if (ans)
		return;

	int rTmp[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (r[i][j] > 0)
				rTmp[i][j] = r[i][j] - 1;
			else
				return;
		}
	}

	if (day > N)
	{
		ans = true;
		return;
	}


	//Print();
	//cout << endl;
	if (day == 1)
	{
		bool ck = false;
		for (int i = 0; i < c.v.size(); i++)
		{
			if (map[day][c.v[i].first][c.v[i].second] == 0)
				continue;
			else
			{
				ck = true;
				break;
			}
		}

		if (!ck)
			Dfs(day+1,r);
	}
	else
	{
		vector<pair<int, int>> tmpV;
		for (int i = 1; i <= 2; i++) //한칸 두칸용
		{
			for (int j = 0; j < 5; j++) //방향
			{
				bool canGo = false;
				for (int m = 0; m < c.v.size(); m++)
				{
					int ny = c.v[m].first + dir[j][0] * i;
					int nx = c.v[m].second + dir[j][1] * i;

					if (nx >= 0 && ny >= 0 && ny < 4 && nx < 4)
					{
						if (map[day][ny][nx] == 0)
						{
							tmpV.push_back(make_pair(ny, nx));
						}
						else
						{
							tmpV.clear();
							canGo = true;
							break;
						}
					}
					else
					{
						tmpV.clear();
						canGo = true;
						break;
					}
				}

				if (!canGo && tmpV.size() == 4)
				{
					vector<pair<int, int>> cTmpV;
					int rainTmp[4];
					int rCnt = 0;
					for (int i = 0; i < tmpV.size(); i++)
					{
						rainTmp[rCnt++] = rTmp[tmpV[i].first][tmpV[i].second];
						rTmp[tmpV[i].first][tmpV[i].second] = 7;
					}

					cTmpV = c.v;
					c.v.swap(tmpV);
					Dfs(day + 1, rTmp);
					c.v.swap(cTmpV);
					rCnt = 0;

					for (int i = 0; i < tmpV.size(); i++)
					{
						rTmp[tmpV[i].first][tmpV[i].second] = rainTmp[rCnt++];
					}

					tmpV.clear();
				}
			}
		}
	}
}

int main(void)
{
	while (true)
	{
		cin >> N;
		if (N == 0)
			break;
		
		for (int n = 1; n <= N; n++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					int num;
					cin >> num;
					map[n][i][j] = num;
					rain[i][j] = 6;
				}
			}
		}
		vector<pair<int, int>> cV;
		cV.push_back(make_pair(1, 1));
		cV.push_back(make_pair(1, 2));
		cV.push_back(make_pair(2, 1));
		cV.push_back(make_pair(2, 2));
		c.v = cV;
		Dfs(1,rain);
		cout << (int)ans << endl;
		ans = false;
		c.v.clear();
	}

}