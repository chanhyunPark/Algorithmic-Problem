#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>

#define MAX 987654321

using namespace std;

typedef struct Node 
{
	int value;
	int clip;
	int time;
public:
	Node() {}
	Node(int value, int clip, int time) : value(value), clip(clip), time(time) {}
}Node;

int S;
int ans = MAX;
int dp[1001][1001];

int Dfs2(int screen, int cnt) 
{
	if (screen > S || cnt > S)
	{
		return 0;
	}

	if (screen == S)
	{
		return 0;
	}

	int &ret = dp[screen][cnt];

	if (ret != -1)
		return ret;

	ret = 0;

	if (screen == 1 && cnt == 0)
	{
		ret += (Dfs2(screen, screen) + 1);
	}
	else
	{
		ret = min(ret, Dfs2(screen, screen + 1) + 1);
		ret = min(ret, Dfs2(screen + cnt, cnt) + 1);
		ret = min(ret, Dfs2(screen - 1, cnt) + 1);
	}

	return ret;
}

void Dfs(int screen, int cnt, int time) //cnt 클립보드 갯수 
{
	if (time > S)
		return;

	if (cnt > S)
		return;

	if (time >= ans)
		return;

	if (screen > S)
		return;

	if (screen == S)
	{
		ans = min(ans, time);
		return;
	}

	//3가지가 있다. 1.복사 저장 2. 화면에 붙여넣기 3. 하나를 삭제
	//1.복사 time == 0이면 첨엔 복사만 가능하다.

	if (time == 0)
	{
		Dfs(screen, screen, time+1); //각각 더해주기만 한다.
	}
	else
	{
		//복사만 하는 경우 스크린과 cnt 갯수가 달라야함
		//덮어쓰기
		Dfs(screen, screen, time+1);
		//붙여넣기만 하는경우
		Dfs(screen + cnt, cnt, time+1);
		//지울 경우
		Dfs(screen - 1, cnt, time+1);
	}
}


int main(void)
{
	cin >> S;

	memset(dp,-1,sizeof(dp));
	//Dfs(1,0,0);
	cout << Dfs2(1,0) << endl;
	//cout << ans << endl;
	queue<Node > q;
	q.push(Node(1,0,0));
	set<pair<int,int>> visit;

	while (!q.empty())
	{
		int value = q.front().value;
		int clip = q.front().clip;
		int time = q.front().time;
		q.pop();

		if (value == S)
		{
			cout << time << "\n";
			return 0;
		}

		if (time < S)
		{
			if (clip <= 1000 && value <= 1000 && time <= 1000)
			{
				if (visit.count({value,value}) == 0)
				{
					visit.insert({ value,value });
					q.push(Node(value, value, time + 1));
				}

				if (visit.count({ value+clip,value }) == 0)
				{
					visit.insert({ value + clip,value });
					q.push(Node(value + clip, clip, time + 1));
				}

				if (visit.count({ value-1,clip }) == 0)
				{
					visit.insert({ value-1,value });
					q.push(Node(value - 1, clip, time + 1));
				}
			}
		}
	} 

	return 0;
}