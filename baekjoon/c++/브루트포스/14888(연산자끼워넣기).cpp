#include<iostream>
using namespace std;

int N;
int num[12];
int opr[4];
int oprn[12];
int maxvalue = -1000000000;
int minvalue = 1000000000;
void update()
{
	int sum = num[0];
	for (int n = 1; n < N; n++)
	{
		if (oprn[n - 1] == 0)
			sum += num[n];
		else if (oprn[n - 1] == 1)
			sum -= num[n];
		else if (oprn[n - 1] == 2)
			sum *= num[n];
		else if (oprn[n - 1] == 3)
			sum /= num[n];
	}

	if (maxvalue < sum)
		maxvalue = sum;

	if (minvalue > sum)
		minvalue = sum;
}
void dfs(int len)
{

	if (len == N - 1)
	{
		update();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (opr[i] > 0)
		{
			oprn[len] = i;
			opr[i]--;
			dfs(len + 1);
			opr[i]++;
		}
	}
}
int main(void)
{
	cin >> N;

	for (int n = 0; n < N; n++)
	{
		cin >> num[n];
	}

	for (int n = 0; n < 4; n++)
	{
		cin >> opr[n];
	}

	dfs(0);

	cout << maxvalue << endl;
	cout << minvalue << endl;
	return 0;
}