#include<iostream>

using namespace std;

int T;
int L, U, X;
int main(void)
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int ans = 0;
		int minV, maxV, curV;
		cin >> minV >> maxV >> curV;
		if (curV >= minV && curV <= maxV)
			ans = 0;
		else if (curV < minV)
			ans = minV - curV;
		else
			ans = -1;
		cout << '#' << t << ' ' << ans << '\n';
	}

}