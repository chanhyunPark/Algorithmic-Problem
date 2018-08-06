#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<deque>
#include<vector>

using namespace std;

typedef struct snack 
{
	pair<int, int> head; // 머리
	pair<int, int> tail; //꼬리
	deque<pair<int, int>> body; // 몸통
	int dir; // 방향
public:
	snack() {}
	snack(pair<int, int> head, pair<int, int> tail, deque<pair<int, int>> &body, int dir)
		:head(head), tail(tail), body(body), dir(dir) {}
}snack;

int N; //보드 크기
int K; //사과 갯수
int L; 
int map[1000][1000];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; //위, 아래, 왼쪽, 오른쪽
char info[100001];
int getDir(int d, char c)
{
	if (c == 'L')
	{
		if (d == 1)
			return 3;
		else if (d == 2)
			return 1;
		else if (d == 0)
			return 2;
		else if (d == 3)
			return 0;
	}
	else if (c == 'D')
	{
		if (d == 1)
			return 2;
		else if (d == 2)
			return 0;
		else if (d == 0)
			return 3;
		else if (d == 3)
			return 1;
	}

	return d;
}
int main(void)
{
	cin >> N;
	cin >> K;
	for (int k = 0; k < K; k++)
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1; // 사과 위치는 1
	}

	cin >> L;
	for (int l = 0; l < L; l++)
	{
		int time;
		char dir;
		cin >> time >> dir;
		info[time] = dir; //시간대에 방향 입력
	}

	deque<pair<int, int>> v;
	snack s = snack(make_pair(1,1), make_pair(1, 1), v, 3); //시작
	
	int time = 0; //0초부터 시작
	bool endFlag = false;
	int appleCnt = 0; // 사과 갯수
	while (true)
	{
		time++; //시간증가
		
		int d = s.dir;

		//head 위치 옮김
		int hy = s.head.first + dir[d][0];
		int hx = s.head.second + dir[d][1];
		int ty = s.tail.first;
		int tx = s.tail.second;
		deque<pair<int, int>> dq = s.body;

		if (info[time] != ' ')
		{
			d = getDir(d, info[time]);
		}

		//꼬리와 만나면 끝
		if (hy == ty && hx == tx)
			break;


		//몸통과 만나면 끝
		for (int i = 0; i < s.body.size(); i++)
		{
			if (hy == s.body[i].first && hx == s.body[i].second)
			{
				endFlag = true;
				break;
			}
		}

		if (endFlag)
			break;

		//벽에 부딪이면 종료
		if (hy <= 0 || hx <= 0 || hy > N || hx > N) 
			break;

		//사과가 있으면
		if (map[hy][hx] == 1)
		{
			map[hy][hx] = 0;
			if (s.head.first == ty && s.head.second == tx)
			{
				s = snack(make_pair(hy,hx), make_pair(ty, tx),dq,d);
			}
			else
			{
				dq.push_back(make_pair(s.head.first, s.head.second));
				s = snack(make_pair(hy, hx), make_pair(ty, tx), dq, d);
			}
		}
		else
		{
			if (s.head.first == ty && s.head.second == tx)
			{
				s = snack(make_pair(hy, hx), make_pair(hy, hx), dq, d);
			}
			else
			{
				if (s.body.size() == 0)
				{
					s = snack(make_pair(hy, hx), make_pair(s.head.first, s.head.second), dq, d);
				}
				else
				{
					ty = dq.front().first;
					tx = dq.front().second;
					dq.pop_front();
					dq.push_back(make_pair(s.head.first, s.head.second));
					s = snack(make_pair(hy, hx), make_pair(ty, tx), dq, d);
				}
			}
		}

	}

	cout << time << endl;
	return 0;
}	