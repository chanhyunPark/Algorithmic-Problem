#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 987654321

typedef struct Node 
{
	int y;
	int x;
	int size;

public:
	Node() {}
	Node(int y, int x, int size) : y(y), x(x), size(size) {}

};


int N;
int map[21][21];
int tmp[21][21];
int dist[21][21];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int time = 0;
int subTime = 0; //bfs를 통해 구한 시간 -1로 초기화 할 것
Node sh;
Node target;
vector<Node> v;

void Print() 
{
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < N; m++)
		{
			cout << map[n][m] << " ";
		}
		cout << endl;
	}
}

void Print2(int y, int x, int r) 
{
	tmp[y][x] = r;
	
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < N; m++)
		{
			cout << tmp[n][m] << " ";
		}
		cout << endl;
	}

}

bool cmp(Node n1, Node n2) 
{
	if (n1.size < n2.size)
		return true;
	else if (n1.size == n2.size)
	{
		if (n1.y < n2.y)
			return true;
		else if (n1.y == n2.y)
		{
			if (n1.x < n2.x)
				return true;
		}
	}

	return false;
}

int Bfs(Node s)
{
	int sT = -1;

	queue<Node> q;

	q.push(s);
	dist[s.y][s.x] = 0;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;

			if (map[ny][nx] <= s.size && dist[ny][nx] > dist[y][x] + 1)
			{
				dist[ny][nx] = dist[y][x] + 1;
				q.push(Node(ny,nx,0));

				if (map[ny][nx] != 0 && map[ny][nx] != s.size) 
					v.push_back(Node(ny,nx,dist[ny][nx]));
			}
		}
	}

	if (v.size() == 0)
		sT = -1;
	else
	{
		sort(v.begin(), v.end(), cmp);
		sT = v.front().size;
		target = v.front();
		v.clear();
	}

	return sT;
}

int main(void)
{
	cin >> N;

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < N; m++)
		{
			cin >> map[n][m];

			if (map[n][m] == 9)
			{
				sh = Node(n, m, 2); //아기 상어 초기화
				map[n][m] = 0;
			}
		}
	}

	int sum = 0;
	int cnt = 0;
	int rank = 1;
	while (true)
	{
		for (int n = 0; n < N; n++)
			for (int m = 0; m < N; m++)
				dist[n][m] = MAX;

		subTime = Bfs(sh);
		
		if (subTime == -1)
			break;

		//cout << "================================\n";
		//Print2(target.y, target.x,rank);
		rank++;

		sum += subTime;
		sh.y = target.y;
		sh.x = target.x;
		map[target.y][target.x] = 0;
		cnt++;

		if (sh.size == cnt)
		{
			cnt = 0;
			sh.size++;
		}
	}

	cout << sum << endl;
	
	return 0;
}