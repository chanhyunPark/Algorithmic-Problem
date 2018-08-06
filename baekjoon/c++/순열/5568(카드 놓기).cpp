#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
set<string> s;
vector<string> v;
bool ck[11];
int N, K;

void Dfs(vector<int> &v1, int idx, int len) 
{
	if (idx > N)
		return;

	if (v1.size() == K)
	{
		do 
		{
			string str;
			for (int i = 0; i < v1.size(); i++)
			{
				str.append(v[v1[i]]);
			}
			s.insert(str);
		} while (next_permutation(v1.begin(), v1.end()));
		return;
	}

	v1.push_back(idx);
	Dfs(v1,idx+1, len+1);
	v1.pop_back();
	Dfs(v1,idx+1,len);
}

int main(void)
{
	cin >> N;
	cin >> K;

	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	vector<int> tmp;
	Dfs(tmp,0,0);
	cout << s.size() << "\n";
}