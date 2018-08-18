#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 18
#define MAX_N 100000

int N, M;
vector<pair<int,int>> v[MAX_N];
int depth[MAX_N];
int parent[MAX_N][MAX];
int cost[MAX_N];
void Dfs(int n,int dist)
{
	for (auto next : v[n])
	{
		if (depth[next.first] == -1)
		{
			parent[next.first][0] = n;
			cost[next.first] = dist + next.second;
			depth[next.first] = depth[n] + 1;
			Dfs(next.first, dist + next.second);
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int n = 0; n < N - 1; n++)
	{
		int y, x, dist;
		scanf("%d%d%d", &y, &x, &dist);
		y--;
		x--;
		v[y].push_back(make_pair(x,dist));
		v[x].push_back(make_pair(y,dist));
	}

	memset(cost, -1 ,sizeof(cost));
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));

	depth[0] = 0;
	cost[0] = 0;
	Dfs(0,0);

	for (int j = 0; j < MAX - 1; j++)
	{
		for (int i = 1; i < N; i++)
		{
			if (parent[i][j] != -1)
			{
				parent[i][j + 1] = parent[parent[i][j]][j];
			}
		}
	}

	scanf("%d", &M);
	for (int m = 0; m < M; m++)
	{
		int u, v;
		int sum = 0;

		scanf("%d%d", &u, &v);
		u--;
		v--;

		int tmpU = u;
		int tmpV = v;

		//depth[u] >= depth[v]가 되도록 필요에 따라 u, v를 스왑
		if (depth[u] < depth[v])
		{
			swap(u, v);
		}

		int sub = depth[u] - depth[v];

		for (int j = 0; sub; j++)
		{
			if (sub % 2)
			{
				u = parent[u][j];
			}
			
			sub /= 2;
		}

		if (u != v)
		{
			for (int j = MAX - 1; j >= 0; j--)
			{
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j])
				{
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			//마지막엔 두 정점 u,v의 부모가 같으므로 한번 더 올림
			u = parent[u][0];
		}

		printf("%d\n", cost[tmpU] + cost[tmpV] - 2 * cost[u]);
	}

	return 0;
}