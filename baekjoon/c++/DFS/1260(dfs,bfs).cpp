#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, V;
vector<int> v[1001];
bool visit[1000];
void dfs(int start)
{
	visit[start] = true;
	cout << start << " ";
	for (int i = 0; i < v[start].size(); i++)
	{
		if (!visit[v[start][i]])
		{
			visit[v[start][i]] = true;
			dfs(v[start][i]);
		}
	}
}

void bfs(int start) 
{
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int value = q.front();
		cout << value << " ";
		q.pop();

		int size = v[value].size();
		for (int i = 0; i < size; i++)
		{
			if (!visit[v[value][i]])
			{
				visit[v[value][i]] = true;
				q.push(v[value][i]);
			}
		}

	}
}

int main(void)
{
	cin >> N >> M >> V;
	for (int m = 0; m < M; m++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	for (int n = 1; n <= N; n++)
		sort(v[n].begin(), v[n].end());

	dfs(V);
	for (int i = 0; i <= N; i++)
		visit[i] = false;
	cout << endl;
	bfs(V);
	cout << endl;

	return 0;
}