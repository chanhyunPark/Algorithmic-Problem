#include<iostream>
#include<cmath>
#include<deque>
#include<algorithm>

using namespace std;

int main(void)
{
	deque<int> dq;
	for (int i = 0; i < 3; i++)
	{
		int num;
		cin >> num;
		dq.push_back(num);
	}

	sort(dq.begin(), dq.end());

	int cnt = 0;
	if (abs(dq[2] - dq[1]) > abs(dq[1] - dq[0]))
	{
		while (true)
		{
			if (dq[1] + 1 < dq[2])
			{
				int tmp = dq[1];
				dq.pop_front();
				dq.pop_front();
				dq.push_front(tmp + 1);
				dq.push_front(tmp);
				cnt++;
			}
			else
				break;
		}
	}
	else
	{
		while (true)
		{
			if (dq[1] - 1 > dq[0])
			{
				int tmp = dq[1];
				dq.pop_back();
				dq.pop_back();
				dq.push_back(tmp - 1);
				dq.push_back(tmp);
				cnt++;
			}
			else
				break;
		}
	}

	cout << cnt << '\n';
	return 0;
}