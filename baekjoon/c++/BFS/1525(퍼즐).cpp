#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

typedef struct Node 
{
	int state;
	int cnt;
public:
	Node() {}
	Node(int state, int cnt) : state(state), cnt(cnt) {}
};

int map[3][3];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int main(void)
{
	int sum = 0;
	int ans = 0;
	int digit = 100000000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> map[i][j];
			sum += digit * map[i][j];
			digit /= 10;
		}
	}
	set<int> visit;
	queue<Node> q;
	q.push(Node(sum,0));
	visit.insert(sum);
	int tmp[3][3];
	while (!q.empty())
	{
		int cur = q.front().state;
		int cnt = q.front().cnt;
		q.pop();

		if (cur == 123456780)
		{
			cout << cnt << endl;
			return 0;
		}

		int y, x;
		for (int i = 2; i >= 0; i--)
		{
			for (int j = 2; j >= 0; j--)
			{
				tmp[i][j] = cur % 10;
				if (tmp[i][j] == 0)
				{
					y = i;
					x = j;
				}
				cur /= 10;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny >= 0 && nx >= 0 && ny < 3 && nx < 3)
			{
				swap(tmp[y][x], tmp[ny][nx]);
				int s = 0;
				int digit = 100000000;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						s += (tmp[i][j] * digit);
						digit /= 10;
					}
				}

				if (visit.find(s) == visit.end())
				{
					visit.insert(s);
					q.push(Node(s,cnt+1));
				}
				swap(tmp[ny][nx], tmp[y][x]);
			}
		}
	}
	cout << -1 << endl;
	return 0;
}