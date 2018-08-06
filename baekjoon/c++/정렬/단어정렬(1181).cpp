#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool cmp2(string s1, string s2)
{
	if (s1.length() == s2.length())
	{
		return s1.compare(s2) < 0 ? 1 : 0;
	}
	else
	{
		return s1.length() > s2.length() ? 0 : 1;
	}
}

int main(void)
{
	int N;
	cin >> N;
	vector<string> sV;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		sV.push_back(str);
	}


	sort(sV.begin(), sV.end(), cmp2);
	sV.erase(unique(sV.begin(),sV.end()), sV.end());

	for (int i = 0; i < sV.size(); i++)
		cout << sV[i] << endl;

	return 0;
}