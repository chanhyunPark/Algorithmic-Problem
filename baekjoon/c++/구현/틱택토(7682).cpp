#include<iostream>
#include<string>
using namespace std;

char map[3][3];
int main(void)
{
	while (true)
	{
		string str;
		cin >> str;

		if (str == "end")
			break;

		int xCnt = 0;
		int oCnt = 0;
		int cnt = 0;
		for (int n = 0; n < 3; n++)
		{
			for (int m = 0; m < 3; m++)
			{
				map[n][m] = str[cnt++];
				if (map[n][m] == 'X')
					xCnt++;
				else if (map[n][m] == 'O')
					oCnt++;
			}
		}

		int ans = 0;
		int xAns = 0;
		int oAns = 0;
		int visit = 0;

		if (xCnt < oCnt)
		{
			cout << "invalid\n";
			continue;
		}
		else
		{
			if (map[0][0] != '.' && map[0][1] == map[0][0] && map[0][2] == map[0][0])
			{
				if (map[0][0] == 'O')
					oAns++;
				else
					xAns++;
				ans++;
			}

			if (map[0][0] != '.' && map[1][0] == map[0][0] && map[2][0] == map[0][0])
			{
				if (map[0][0] == 'O')
					oAns++;
				else
					xAns++;
				ans++;
			}

			if (map[0][0] != '.' && map[1][1] == map[0][0] && map[2][2] == map[0][0])
			{
				if (map[0][0] == 'O')
					oAns++;
				else
					xAns++;
				ans++;
			}

			if (map[0][1] != '.' && map[1][1] == map[0][1] && map[2][1] == map[0][1])
			{
				if (map[0][1] == 'O')
					oAns++;
				else
					xAns++;
				ans++;
			}

			if (map[0][2] != '.' && map[1][1] == map[0][2] && map[2][0] == map[0][2])
			{
				if (map[0][2] == 'O')
					oAns++;
				else
					xAns++;
				ans++;
			}


			if (map[0][2] != '.' && map[1][2] == map[0][2] && map[2][2] == map[0][2])
			{
				if (map[0][2] == 'O')
					oAns++;
				else
					xAns++;
				ans++;
			}

			if (map[1][0] != '.' && map[1][1] == map[1][0] && map[1][2] == map[1][0])
			{
				if (map[1][0] == 'O')
					oAns++;
				else
					xAns++;
				ans++;
			}

			if (map[2][0] != '.' && map[2][1] == map[2][0] && map[2][2] == map[2][0])
			{
				if (map[2][0] == 'O')
					oAns++;
				else
					xAns++;
				ans++;
			}
		}

		if (ans > 1)
		{
			if (xAns == 2 && xCnt == oCnt+1)
			{
				cout << "valid\n";
				continue;
			}

			cout << "invalid\n";
			continue;
		}

		if (ans == 1)
		{
			if (oAns > 0 && xCnt == oCnt)
			{
				cout << "valid\n";
				continue;
			}

			if (xAns > 0 && xCnt == oCnt + 1)
			{
				cout << "valid\n";
				continue;
			}

			cout << "invalid\n";
			continue;
		}

		if (ans == 0)
		{
			if (xCnt + oCnt == 9 && xCnt == oCnt+1)
				cout << "valid\n";
			else
				cout << "invalid\n";
		
			continue;
		}
	}

	return 0;
}