#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

char x[1001];
char y[1001];
int d[1001][1001];
int ck[1001][1001];
int xcnt, ycnt;
string str;
int main(void)
{
	for (int t = 0; t < 2; t++)
	{
		string tmp;
		cin >> tmp;
		if (t == 0)
		{
			for (unsigned int i = 0; i < tmp.size(); i++)
			{
				x[i+1] = tmp[i];
				xcnt = tmp.size();
			}
		}
		else if (t == 1)
		{
			for (unsigned int i = 0; i < tmp.size(); i++)
			{
				y[i+1] = tmp[i];
				ycnt = tmp.size();
			}
		}
	}

	for (int i = 1; i <= xcnt; i++)
	{
		for (int j = 1; j <= ycnt; j++)
		{
			if (x[i] == y[j])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
				ck[i][j] = 3;
			}
			else
			{
				d[i][j] = d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1];
				if (d[i][j] == d[i - 1][j])
					ck[i][j] = 4;
				else
				{
					ck[i][j] = 5;
				}
			}
		}
	}

	int idxX = xcnt;
	int idxY = ycnt;
	while (ck[idxX][idxY] != 0)
	{
		if (ck[idxX][idxY] == 3)
		{
			str += x[idxX];
			idxX--;
			idxY--;
		}
		else if (ck[idxX][idxY] == 4)
		{
			idxX--;
		}
		else if (ck[idxX][idxY] == 5)
		{
			idxY--;
		}
	}
	reverse(str.begin(),str.end());
	cout << d[xcnt][ycnt] << '\n';
	cout << str << '\n';
}