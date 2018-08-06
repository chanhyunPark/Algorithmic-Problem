ㅍ#include<iostream>
#include<queue>
using namespace std;

typedef struct Node 
{
	int idx;
	int cnt;
	int up;
	int down;
public:
	Node() {}
	Node(int idx, int cnt,int up, int down) : idx(idx), cnt(cnt), up(up), down(down) {}

};

int F, S, G, U, D;
bool visit[10000001][2];
int main(void)
{
	cin >> F >> S >> G >> U >> D;
	queue<Node> q;
	q.push(Node(S,0,0,0));
	int ans = -1;
	while (!q.empty())
	{
		int cur = q.front().idx;
		int cnt = q.front().cnt;
		int up = q.front().up;
		int down = q.front().down;
		q.pop();

		if (cur == G)
		{
			ans = cnt;
			break;
		}
		
		if (cur + U <= F && !visit[cur + U][0])
		{
			visit[cur + U][0] = true;
			q.push(Node(cur + U, cnt + 1, up, down));
		}

		if (cur - D >= 0 && !visit[cur - D][1])
		{
			visit[cur - D][1] = true;
			q.push(Node(cur - D, cnt+1, up, down));
		}
	}

	if (ans == -1)
		cout << "use the stairs" << endl;
	else
		cout << ans << endl;
}