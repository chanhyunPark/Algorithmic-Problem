#include<iostream>

using namespace std;

long long int combi[1001][1001];

int N, K;
long long int getCombi(int n, int k)
{
	if (k == 0 || k == n) 
		return combi[n][k] = 1;
	if (combi[n][k] != 0) 
		return combi[n][k];
	if (k > n - k) 
		return combi[n][k] = getCombi(n, n - k);
	return 
		combi[n][k] = getCombi(n - 1, k) + getCombi(n - 1, k - 1);
}

int main(void)
{
	cin >> N >> K;

	cout << getCombi(N, K) << '\n';
	return 0;
}