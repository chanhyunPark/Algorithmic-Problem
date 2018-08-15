#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>

using namespace std;

long long combi[2010][2010];

long long N, K, M;
long long getCombi(long long n, long long k)
{
	if (k == 0 || k == n) 
		return combi[n][k] = 1;
	if (combi[n][k] != 0) 
		return combi[n][k];
	
	return combi[n][k] = (getCombi(n - 1, k) + getCombi(n - 1, k - 1) % M);
}

vector<long long> get_digit(long long n, long long b)
{
	vector<long long> d;

	while (n)
	{
		d.push_back(n % b);
		n /= b;
	}

	return d;
}

long long lucas_theorem(long long n, long long k, long long p)
{
	long long ret = 1;
	vector<long long> nd = get_digit(n, p), kd = get_digit(k, p);

	for (int i = 0; i < max(nd.size(), kd.size()); i++)
	{
		long long nn, kk;

		if (i < nd.size())
			nn = nd[i];
		else
			nn = 0;

		if (i < kd.size())
			kk = kd[i];
		else
			kk = 0;

		if (nn < kk)
			return 0;

		ret = (ret * getCombi(nn, kk) % M);
	}
	return ret;
}

int main(void)
{
	cin >> N >> K >> M;

	cout << lucas_theorem(N, K, M) % M << '\n';
	return 0;
}