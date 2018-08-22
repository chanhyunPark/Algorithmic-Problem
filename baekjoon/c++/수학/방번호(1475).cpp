#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int num[11];
int main(void)
{
	string str;
	cin >> str;

	int cnt = -1;
	for (int n = 0; n < str.size(); n++)
	{
		num[str[n] - '0']++;

		if (str[n] - '0' != 6 && str[n] - '0' != 9)
		{
			cnt = max(cnt, num[str[n] - '0']);
		}
	}

	int sixAndNine = 0;
	if (cnt < num[6] || cnt < num[9])
	{
		if (num[6] == 0)
		{
			if (num[9] % 2 == 0)
				sixAndNine = num[9] / 2;
			else
				sixAndNine = 1 + (num[9] / 2);
		}
		else if (num[9] == 0)
		{
			if (num[6] % 2 == 0)
				sixAndNine = num[6] / 2;
			else
				sixAndNine = 1 + (num[6] / 2);
		}

		if (num[6] != 0 && num[9] != 0)
		{
			if (num[6] != num[9])
			{
				if ((num[6] + num[9]) % 2 == 0)
					sixAndNine = (num[6] + num[9]) / 2;
				else
					sixAndNine = 1 + ((num[6] + num[9]) / 2);

			}
			else if (num[6] == num[9])
				sixAndNine = num[6];
		}

		if (cnt < sixAndNine)
			cnt = sixAndNine;
	}

	cout << cnt << endl;
	return 0;
}