#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

typedef struct cheeze{

	int y;
	int x;
	int cnt;
public:
	cheeze() {}
	cheeze(int y, int x, int cnt) : y(y), x(x), cnt(cnt) {}
};

int H, W, N; //높이, 폭, 치즈의 수
char map[1001][1001];
bool visit[1001][1001];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int main(void)
{
	cin >> H >> W >> N;
	cheeze c;
	for (int h = 0; h < H; h++)
	{
		string str;
		cin >> str;
		for (int w = 0; w < W; w++)
		{
			map[h][w] = str[w];
			if (map[h][w] == 'S') //시작 위치
				c = cheeze(h,w,0);
		}
	}

	vector<cheeze> v;
	for (int n = 1; n <= N; n++)
	{
		for (int h = 0; h < H; h++)
		{
			for (int w = 0; w < W; w++)
			{
				if (map[h][w]-'0' == n)
				{
					v.push_back(cheeze(h,w,0));
				}
			}
		}
	}

	cheeze s = c;
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		cheeze end = v[i];
		queue<cheeze> q;
		memset(visit,false, sizeof(visit));
		q.push(s);
		while (!q.empty())
		{
			int y = q.front().y;
			int x = q.front().x;
			int cnt = q.front().cnt;
			q.pop();

			if (y == end.y && x == end.x)
			{
				s = cheeze(y,x,0);
				ans += cnt;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if (ny >= 0 && nx >= 0 && ny < H && nx < W)
				{
					if (!visit[ny][nx] && map[ny][nx] != 'X')
					{
						visit[ny][nx] = true;
						q.push(cheeze(ny,nx,cnt+1));
					}
				}
			}
		}
	}
	cout << ans << '\n';
}