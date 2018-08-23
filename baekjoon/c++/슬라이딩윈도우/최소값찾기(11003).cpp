#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;

int N, L;
int minValue = 987654321;
int num[5000001];
int main(void)
{
	deque<int> deq;
	scanf("%d %d", &N, &L);
	for (int n = 0; n < N; n++)
	{
		scanf("%d", &num[n]);
		if (deq.size() == 0)
			deq.push_front(num[n]);
		else
		{
			while (deq.back() > num[n])
			{
				deq.pop_back();
				if (deq.size() == 0)
					break;
			}
			deq.push_back(num[n]);
		}

		if (n >= L && deq.front() == num[n - L])
		{
			deq.pop_front();
		}

		printf("%d ", deq.front());
	}

	return 0;
}