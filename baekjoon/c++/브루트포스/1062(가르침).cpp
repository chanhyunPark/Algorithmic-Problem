#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, K;
int al[51];
int ans = 0;
vector<char> v[50];
void Dfs(int cnt, int mask, int idx) 
{
	int ck = 0;

	if (idx > 26)
		return;

	if (cnt == K)
	{
		for (int i = 0; i < N; i++)
		{
			if ((mask | al[i]) == mask)
				ck++;
		}
		ans = max(ans, ck);
		return;
	}

	if (idx == 0 || idx == 2 || idx == 8 || idx == 13 || idx == 19)
	{
		Dfs(cnt, mask, idx + 1);
	}
	else
	{
		if(cnt < K)
			Dfs(cnt+ 1, (mask | (1 << idx)), idx + 1);
		Dfs(cnt, mask, idx + 1);
	}
}

int main(void)
{
	cin >> N >> K;
	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;
		for (int s = 0; s < str.size(); s++)
		{
			al[n] = al[n] | (1 << (int)(str[s] - 'a'));
		}
	}
	int mask = (1 << 0) | (1 << 2) | (1 << 8) | (1 << 13) | (1 << 19);
	Dfs(5,mask,0);

	cout << ans << '\n';
	return 0;
}