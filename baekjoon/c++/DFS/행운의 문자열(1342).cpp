#include<iostream>
#include<string>
#include<string.h>

using namespace std;

string s;
int al[26];
int ans = 0;
void Dfs(int len, int idx) 
{
	if (len == s.length())
	{
		ans++;
		return;
	}

	for (int i = 0; i < 26; i++)
	{
		if (al[i] > 0 && i != idx)
		{
			al[i]--;
			Dfs(len+1, i);
			al[i]++;
		}
	}
}

int main(void)
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		al[s[i] - 'a']++;
	}
	Dfs(0,-1);
	cout << ans << "\n";
}