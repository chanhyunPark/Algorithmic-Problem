#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int rm;
int parent[51];
bool visit[51];
vector<int> v[51];
int main(void)
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		int value = 0;
		cin >> value;
		parent[n] = value; //부모 저장
	}

	int root = 0;
	for (int n = 0; n < N; n++)
	{
		int value = 0;
		value = parent[n];
		if (value == -1)
		{
			root = n;
			continue;
		}

		v[value].push_back(n);
		v[n].push_back(value);
	}

	cin >> rm; // 제거할 노드
	queue<int> q;
	q.push(rm);
	visit[rm] = true;
	int ans = 0;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		int size = v[tmp].size();
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			if (!visit[v[tmp][i]] && parent[tmp] != v[tmp][i])
			{
				flag = true;
				q.push(v[tmp][i]);
				visit[v[tmp][i]] = true;
			}
		}
	}

	if(!visit[root])
	{
		q.push(root);
		visit[root] = true;
		while (!q.empty())
		{
			int tmp = q.front();
			q.pop();
			int size = v[tmp].size();
			bool flag = false;
			for (int i = 0; i < size; i++)
			{
				if (!visit[v[tmp][i]] && parent[tmp] != v[tmp][i])
				{
					flag = true;
					q.push(v[tmp][i]);
					visit[v[tmp][i]] = true;
				}
			}

			if (!flag)
				ans++;
		}
    }
	cout << ans << endl;
}