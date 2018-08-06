#include <iostream>
#include <cstring>
using namespace std;
int memo[100] = {1,1};

int func(int n)
{
	if (n <= 1)
		return memo[n];
	else
	{
		if (memo[n] > 0)
			return memo[n];
		return memo[n] = func(n - 1) + func(n-2);
	}
}

int main() {

	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		if (n == 0) 
			cout << "1 0\n";
		else if (n == 1) 
			cout << "0 1\n";
		else {
			func(n);
			cout << memo[n - 2] << " " << memo[n - 1] << "\n";
		}
	}
	return 0;
}