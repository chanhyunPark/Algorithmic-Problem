#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

typedef struct Map
{
	int p;
	short flag = 0;
	int cnt;

public:
	Map() {}
	Map(int p, short flag, int cnt) : p(p), flag(flag), cnt(cnt) {}
};

int T;
int N, M, K;
bool visit[700][700];
Map sepo[700][700];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int main(void)
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int ans = 0;
		
		cin >> N >> M >> K;

		//초기화 작업
		memset(visit, false, sizeof(visit));
		for (int n = 0; n < 700; n++)
		{
			for (int m = 0; m < 700; m++)
				sepo[n][m] = Map(0, -1,0);
		}

		queue<pair<int,int>> q;
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				int num;
				cin >> num;
				sepo[n+300][m+300] = Map(num,0,0); //초기상태는 비활성화 상태
				q.push(make_pair(n+300, m+300));
			}
		}

		for (int k = 0; k <= K; k++)
		{
			int size = q.size();
			memset(visit, false, sizeof(visit));
			for (int i = 0; i < size; i++)
			{
				int n = q.front().first;
				int m = q.front().second;
				q.pop();

				Map &tmp = sepo[n][m];

				if (!visit[n][m] && tmp.p != 0) //방문하지 않고 활성시간이 0이 아니면 활성세포
				{
					visit[n][m] = true;

					if (tmp.flag == 0 || tmp.flag == 3)
					{
						if (tmp.flag == 3) //막 번식상태에서 비활성화
						{
							tmp.cnt++;
							tmp.flag = 0;
						}

						if (tmp.cnt < tmp.p) //활성화 타이밍이 아직 아니라면
						{
							tmp.cnt++;
							q.push(make_pair(n,m));
						}
						else if (tmp.cnt == tmp.p) //활성화 타이밍이 맞으면
						{
							tmp.cnt++;
							tmp.flag = 1; //활성화
							q.push(make_pair(n,m));
							continue;
						}
					}

					if (tmp.flag == 1)
					{
						if (tmp.p < tmp.cnt && tmp.cnt <= tmp.p * 2)
						{
							if (tmp.cnt == tmp.p * 2)
							{
								sepo[n][m].flag = 2;
							}
							else
							{
								tmp.cnt++;
								q.push(make_pair(n,m));
							}

							for (int i = 0; i < 4; i++)
							{
								int ny = n + dir[i][0];
								int nx = m + dir[i][1];

								if (ny < 0 || ny > 700 || nx < 0 || nx > 700)
									continue;

								if (!visit[ny][nx])
								{
									if (sepo[ny][nx].p == 0)
									{
										visit[ny][nx] = true;
										sepo[ny][nx] = Map(tmp.p, 3, 0);
										q.push(make_pair(ny,nx));
									}
								}
								else //방문되어 있으면
								{
									if (sepo[ny][nx].flag == 3) //막 번식되어 있는 세포라면
									{
										if (sepo[ny][nx].p < tmp.p)
										{
											sepo[ny][nx].p = tmp.p;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		cout << "#" << t << " " << q.size() << "\n";
	}

}