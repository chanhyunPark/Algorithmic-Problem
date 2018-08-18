#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct bead 
{
	int y;
	int x;
public:
	bead() {}
	bead(int y, int x) : y(y), x(x) {}
};

bead r, b, e;
int N, M; //가로 세로
char map[15][15];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int ans = 987654321;
vector<int> ansV;
void print(bead b, bead r) 
{
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (r.y == n && r.x == m)
				cout << "R" << " ";
			else if (b.y == n && b.x == m)
				cout << "B" << " ";
			else if (map[n][m] == 'O')
				cout << "O" << " ";
			else
				cout << map[n][m] << " ";
		}
		cout << "\n";
	}
}

void Dfs(bead b, bead r, int d, vector<int> v, int cnt)
{
	if (cnt > 10)
		return;

	if (ans < cnt)
		return;

	//종결조건은 구멍에 들어가면 끝나야 함
	if (d != -1 && cnt <= 10)
	{
		int by = b.y;
		int bx = b.x;
		//파란색 구슬부터 검사한다. 파란색이 빠지면 죽음
		while (true)
		{
			by = by + dir[d][0];
			bx = bx + dir[d][1];

			if (by == e.y && bx == e.x)
			{
				return;
			}

			if (by >= 1 && bx >= 1 && by < N - 1 && bx < M - 1)
			{
				if (map[by][bx] == '.')
				{
					//print(bead(by, bx), r);
					//cout << "\n";
					continue;
				}
				else
				{
					by -= dir[d][0];
					bx -= dir[d][1];
					break;
				}
			}
			else
			{
				by -= dir[d][0];
				bx -= dir[d][1];
				break;
			}
		}

		int ry = r.y;
		int rx = r.x;

		while (true)
		{
			ry = ry + dir[d][0];
			rx = rx + dir[d][1];

			if (ry == e.y && rx == e.x)
			{
				if (ans > cnt)
				{
					ans = cnt;
					ansV.swap(v);
				}
				return;
			}

			if (ry >= 1 && rx >= 1 && ry < N - 1 && rx < M - 1)
			{
				if (map[ry][rx] == '.')
				{
					//print(bead(by,bx), bead(ry,rx));
					//cout << "\n";
					continue;
				}
				else
				{
					ry -= dir[d][0];
					rx -= dir[d][1];
					break;
				}
			}
			else
			{
				ry -= dir[d][0];
				rx -= dir[d][1];
				break;
			}
		}

		if (by == ry && bx == rx)
		{
			switch (d)
			{
				case 0: //위
					if (r.y < b.y)
						by = by - dir[d][0];
					else
						ry = ry - dir[d][0];
					break;
				case 1: //아래
					if (r.y < b.y)
						ry = ry - dir[d][0];
					else
						by = by - dir[d][0];
					break;
				case 2: //왼쪽
					if (r.x < b.x)
						bx = bx - dir[d][1];
					else
						rx = rx - dir[d][1];
					break;
				case 3: //오른쪾
					if (r.x > b.x)
						bx = bx - dir[d][1];
					else
						rx = rx - dir[d][1];
					break;
				default:
					break;
			}
		}
		r = bead(ry,rx);
		b = bead(by,bx);
	}

	//방향전환
	for (int i = 0; i < 4; i++)
	{
		//빨간 구슬만 비교
		int ny = r.y + dir[i][0];
		int nx = r.x + dir[i][1];
		int by = b.y + dir[i][0];
		int bx = b.x + dir[i][1];
		if ((ny >= 1 && nx >= 1 && ny < N - 1 && nx < M - 1) ||
			(by >= 1 && bx >= 1 && by < N - 1 && bx < M - 1))
		{
			v.push_back(i);
			Dfs(b,r,i,v,cnt+1);
			v.pop_back();
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;
		for (int m = 0; m < M; m++)
		{
			map[n][m] = str[m];
			if (map[n][m] == 'R')
			{
				r = bead(n, m);
				map[n][m] = '.';
			}
			else if (map[n][m] == 'B')
			{
				b = bead(n, m);
				map[n][m] = '.';
			}
			else if (map[n][m] == 'O')
			{
				e = bead(n, m);
				map[n][m] = '.';
			}
		}
	}
	vector<int> v;
	Dfs(b, r, -1, v, 0);

	if (ans == 987654321)
	{
		cout << -1 << "\n";
		return 0;
	}
	cout << ans << "\n";
	return 0;
}