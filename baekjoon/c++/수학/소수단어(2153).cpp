#include<iostream>
#include<string>
using namespace std;

int arr[1000001];
int main(void)
{
	for (int i = 2; i <= 1000000; i++)
		arr[i] = i;

	for (int i = 2; i <= 1000; i++)
	{
		if (arr[i] == 0)
			continue;

		for (int j = i + i; j <= 1000000; j += i)
			arr[j] = 0;
	}



	string str;
	cin >> str;

	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int num = 0;

		if (str[i] >= 'a' && str[i] <= 'z')
			num = str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			num = str[i] - 'A' + 27;

		ans += num;
	}

	if (arr[ans] != 0 || ans == 1)
		cout << "It is a prime word.\n";
	else
		cout << "It is not a prime word.\n";

	return 0;
}