#include<iostream>

using namespace std;

int num[1001];
int main(void)
{
	int N, K;

	cin >> N >> K;
	for (int i = 2; i <= N; i++)
	{
		num[i] = i;
	}

	int cnt = 0;
	for (int i = 2; i <= N; i++)
	{	
		if (num[i] != 0)
		{
			cnt++;
			num[i] = 0;
			if (cnt == K)
			{
				cout << i << endl;
				return 0;
			}
		}

		for (int j = 2; j <= N; j++)
		{
			if (num[j] != i && num[j] % i == 0 && num[j] != 0)
			{
				cnt++;
				num[j] = 0;
				
				if (cnt == K)
				{
					cout << j << endl;
					return 0;
				}
			}
		}
	}
}