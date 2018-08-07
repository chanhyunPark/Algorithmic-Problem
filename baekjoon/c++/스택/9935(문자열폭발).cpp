#include<iostream>
#include<stack>
#include<string>
#include<string.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char str[1000001];
	char explosion[1000001];
	char res[1000001];

	cin >> str;
	cin >> explosion;

	int len = strlen(str);
	int bLen = strlen(explosion);

	int j = 0;
	for (int i = 0; i <= len; i++)
	{
		if (strncmp(res + j - bLen, explosion, bLen) == 0)
			j -= bLen;
		
		res[j++] = str[i];
	}

	if (!res[0])
		cout << "FRULA\n";
	else
		cout << res << "\n";

	return 0;
}