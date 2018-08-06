#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int L, C; //3 <= L <= C <= 15
vector<char> v;
vector<char> str;
int flag = 0;
int cnt = 0;
void dfs(int start, int len) 
{
	if (len == L)
	{
		sort(str.begin(), str.end());
		for (int v = 0; v < L; v++)
		{
			int tmp = str[v];
			if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u')
			{
				flag++;
			}
			else
				cnt++;
		}

		if (flag >= 1 && cnt >= 2)
		{
			for (int s = 0; s < L; s++)
				cout << str[s];

			cout << endl;
		}
		flag = 0;
		cnt = 0;
		return;
	}

	for (int i = start; i < C; i++)
	{
		str.push_back(v[i]);
		dfs(i+1, len+1);
		str.pop_back();
	}
}
int main(void)
{
	cin >> L >> C;
	for (int c = 0; c < C; c++)
	{
		char input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	dfs(0,0);

	//서로 다른 L개의 알파벳 소문자들로 구성
	//최소 한개의 모음과 최소 두개의 자음으로 구성 알파벳이 증가하는 순서로 배열되었을 것
}