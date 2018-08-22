#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int cnt = 0;
	int ans = 0;
	int before = 0;
	vector<int> v;
	for (int n = 0; n < N; n++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());

	//N의 진짜 약수가 모두 주어지기 때문에 가장 작은 수와 가장 큰 수를 곱하면 N이 나온다
	cout << v[0] * v[N - 1] << '\n';

	return 0;
}#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

int N; // 15

int map[20][20];
int visit[20];
int ans = 0;

bool isCheck(int y) 
{
	for (int n = 1; n < y; n++)
	{
		if (visit[y] == visit[n])
			return false;

		if (abs(visit[y] - visit[n]) == abs(y - n))
			return false;
	}
	return true;
}


void Dfs(int row) 
{	
	if (row == N)
	{
		ans++;
		return;
	}

	for (int j = 1; j <= N; j++)
	{	
		visit[row + 1] = j;

		if (isCheck(row + 1))
		{
			Dfs(row + 1);
		}
		else
			visit[row + 1] = 0;
	}

	visit[row] = 0;
}

int main(void)
{
	cin >> N; //퀸 수
	//memset(visit,-1,sizeof(visit));
	for (int i = 1; i <= N; i++)
	{
		visit[1] = i;
		Dfs(1);
	}
	

	cout << ans << endl;
}