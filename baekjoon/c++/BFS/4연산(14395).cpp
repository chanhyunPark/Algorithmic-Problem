#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

typedef struct Node 
{
	long long sum;
	string s;

public:
	Node() {}
	Node(int sum, string s) : sum(sum), s(s) {}

};


int N, T;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> T;

	if (N == T)
	{
		cout << "0\n";
		return 0;
	}
	else
	{
		queue<Node> q;
		set<long long> s;
		q.push(Node(N,""));

		while (!q.empty())
		{
			long long num = q.front().sum;
			string con = q.front().s;
			q.pop();

			if (num == T)
			{
				cout << con << "\n";
				return 0;
			}
			
			long long tmp = 0;
			//곱하기
			tmp = num * num;
			if (s.count(tmp) == 0)
			{
				s.insert(tmp);
				q.push(Node(tmp, con + "*"));
			}

			tmp = num + num;
			if (s.count(tmp) == 0)
			{
				s.insert(tmp);
				q.push(Node(tmp, con + "+"));
			}

			tmp = num - num;
			if (s.count(tmp) == 0)
			{
				s.insert(tmp);
				q.push(Node(tmp, con + "-"));
			}

			if (num != 0)
			{
				tmp = num / num;
				if (s.count(tmp) == 0)
				{
					s.insert(tmp);
					q.push(Node(tmp, con + "/"));
				}
			}
		}
	}

	cout << "-1\n";
	return 0;
}