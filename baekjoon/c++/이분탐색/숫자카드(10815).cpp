#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> sang;
int N, M;
int found[50000];

void Foundnum(int num) 
{
	int left = 0, right = N - 1;
	int mid;
	while (left <= right) 
	{
		mid = (left + right) / 2;

		if (num == sang[mid])
		{
			printf("1 ");
			return;
		}
		else if (num >= sang[mid])
			left = mid + 1;
		else if (num < sang[mid])
			right = mid - 1;	
	}
	printf("0 ");
	return;
}
int main(void) {
	int c;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &c);
		sang.push_back(c);
	}
	sort(sang.begin(), sang.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		scanf("%d", &num);
		Foundnum(num);
	}

	return 0;
}