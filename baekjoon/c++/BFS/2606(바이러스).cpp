#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N; //컴퓨터 갯수
int k; //쌍의 갯수

queue<int> q;
bool visit[101];
int main(void)
{
	vector<int> v[101]; // 컴퓨터 벡터
	cin >> N;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		v[c1].push_back(c2);
		v[c2].push_back(c1);
	}

	int cnt = 0; //바이러스에 걸린 갯수
	q.push(1);
	visit[1] = true;
	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		for (int i = 0; i < v[value].size(); i++)
		{
			if (!visit[v[value][i]])
			{
				visit[v[value][i]] = true;
				q.push(v[value][i]);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}