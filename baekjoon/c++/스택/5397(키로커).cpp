#include<iostream>
#include<string>
#include<list>
using namespace std;

int T;
int main(void)
{
	cin >> T; //test_case

	for (int t = 0; t < T; t++)
	{
		list<char> pwd; //비밀번호를 알아내야함
		string str;
		cin >> str;
		int size = str.size();
		list<char>::iterator p = pwd.begin();
		for (int s = 0; s < size; s++)
		{
			char c = str[s];
			switch (c)
			{
				case '<' :
					if (p != pwd.begin())
						p--;
					break;
				case '>':
					if (p != pwd.end())
						p++;
					break;
				case '-':
					if (p != pwd.begin())
					{
						p = pwd.erase(--p);
					}
					break;
				default:
					p = pwd.insert(p, c); //단어인 경우 백으로 차례로 넣음
					p++;
				break;
			}
		}

		int psize = pwd.size();
		for (int i = 0; i < psize; i++)
		{
			cout << pwd.front();
			pwd.pop_front();
		}
		cout << endl;
	}
	return 0;
}