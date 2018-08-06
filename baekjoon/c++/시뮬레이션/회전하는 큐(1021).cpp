#include<iostream>
#include<deque>
using namespace std;

int N;
int M;
deque<int> dq;
deque<int>::iterator iter; 
int main(void)
{
	cin >> N >> M;

	for (int n = 1; n <= N; n++)
	{
		dq.push_back(n);
	}

	int cnt = 0;
	for (int m = 0; m < M; m++)
	{
		int loc;
		cin >> loc;
		int size = dq.size();
		int index = 0;

		for (iter = dq.begin(); iter < dq.end(); iter++)
		{
			if (*iter == loc)
				break;
			index++;
		}

		int left = index;
		int right = size - index;
		if (left < right)
		{
			for (int i = 0; i < left; i++)
			{
				dq.push_back(dq.at(0));
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();
		}
		else
		{
			for (int i = 0; i < right; i++)
			{
				dq.push_front(dq.at(size-1));
				dq.pop_back();
				cnt++;
			}
			dq.pop_front();
		}
	}
	cout << cnt << endl;
	return 0;
}