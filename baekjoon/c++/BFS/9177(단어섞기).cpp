#include<iostream>
#include<string>
#include<queue>

using namespace std;

typedef struct Word
{
	string str;
	int strF;
	int strS;
public:
	Word() {}
	Word(string str, int strF, int strS) : str(str), strF(strF), strS(strS) {}

};

bool visit[250][250];
int main(void)
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		string s1, s2, sE;
		cin >> s1 >> s2 >> sE;
		memset(visit,false, sizeof(visit));


		if (!sE.compare(s1 + s2) || !sE.compare(s2 + s1))
		{
			cout << "Data set " << t << ": yes\n";
			continue;
		}

		bool ans = false;
		int len1 = s1.size();
		int len2 = s2.size();
		int lenE = len1 + len2;

		queue<Word> q;
		q.push(Word("",0,0));
		q.push(Word("",0,0));
		
		while (!q.empty())
		{
			string str = q.front().str;
			int pos1 = q.front().strF;
			int pos2 = q.front().strS;
			q.pop();

			if (str.size() == lenE && str.compare(sE) == 0)
			{
				ans = true;
				break;
			}

			if (pos1 < len1)
			{
				if (!visit[pos1 + 1][pos2] && s1[pos1] == sE[str.size()])
				{
					q.push(Word(str + s1[pos1], pos1 + 1, pos2));
					visit[pos1 + 1][pos2] = true;
				}
			}

			if (pos2 < len2)
			{
				if (!visit[pos1][pos2 + 1] && s2[pos2] == sE[str.size()])
				{
					q.push(Word(str + s2[pos2], pos1, pos2+1));
					visit[pos1][pos2 + 1] = true;
				}
			}
		}

		if(ans)
			cout << "Data set " << t << ": yes\n";
		else
			cout << "Data set " << t << ": no\n";


	}

}