#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> sang;
int N, M;
int found[550000];

int Foundnum(int num, bool flag)
{
	int cnt = 0;
	int left = 0, right = N - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (num == sang[mid])
		{
			if(!flag)
				found[mid]++;

			return mid;
		}
		else if (num >= sang[mid])
			left = mid + 1;
		else if (num < sang[mid])
			right = mid - 1;
	}
	return -1;
}
int main(void) {

	int c;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &c);
		sang.push_back(c);
	}

	sort(sang.begin(), sang.end());

	for (int i = 0; i < N; i++)
	{
		int num = Foundnum(sang[i], false);
	}


	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		scanf("%d", &num);

		int idx = Foundnum(num, true);

		if (idx == -1)
			printf("0 ");
		else
			printf("%d ", found[idx]);
	}

	return 0;

}