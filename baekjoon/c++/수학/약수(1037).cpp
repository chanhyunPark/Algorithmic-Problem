#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int cnt = 0;
	int ans = 0;
	int before = 0;
	vector<int> v;
	for (int n = 0; n < N; n++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());

	//N의 진짜 약수가 모두 주어지기 때문에 가장 작은 수와 가장 큰 수를 곱하면 N이 나온다
	cout << v[0] * v[N - 1] << '\n';

	return 0;
}