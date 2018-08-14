#include<iostream>
#include<string>
using namespace std;
typedef struct King 
{
	int y;
	int x;
public:
	King() {}
	King(int y, int x) : y(y), x(x) {}

};
int map[10][10];
King king, stone;
int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1} };
//R, L, B, T, RT, LT, RB, LB
void Print() 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 1)
				cout << "★";
			else if (map[i][j] == 2)
				cout << "■";
			else
				cout << "□";
		}
		
		cout << endl;
	}
}

int getDir(string str)
{
	if (str == "R")
		return 0;
	else if (str == "L")
		return 1;
	else if (str == "B")
		return 2;
	else if (str == "T")
		return 3;
	else if (str == "RT")
		return 4;
	else if (str == "LT")
		return 5;
	else if (str == "RB")
		return 6;
	else if (str == "LB")
		return 7;

}


int main(void)
{
	string k, s;
	int N;
	cin >> k >> s >> N;

	king = King(7 - (k[1] - '1'), k[0] - 'A');
	stone = King(7 - (s[1] - '1'), s[0] - 'A');
	//king - 1, stone - 2
	map[king.y][king.x] = 1;
	map[stone.y][stone.x] = 2;
	//Print();
	
	//행은 가장 아래가 1이고 위가 8
	//왼쪽 아래 코너는 A1 오른쪽 칸 B1

	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;
		int d = getDir(str);
		//먼저 king 위치 받기
		int ky = king.y + dir[d][0];
		int kx = king.x + dir[d][1];

	//	Print();
		if (ky >= 0 && kx >= 0 && ky < 8 && kx < 8)
		{
			if (map[ky][kx] == 2) // 돌이 있다면
			{
				//돌의 방향을 체크
				int sy = stone.y + dir[d][0];
				int sx = stone.x + dir[d][1];

				if (sy < 0 || sx < 0 || sy > 7 || sx > 7)
					continue;

				map[stone.y][stone.x] = 0;
				map[king.y][king.x] = 0;
				map[sy][sx] = 2;
				map[ky][kx] = 1;
				stone = King(sy, sx);
				king = King(ky, kx);
			}
			else if (map[ky][kx] == 0)
			{
				map[king.y][king.x] = 0;
				map[ky][kx] = 1;
				king = King(ky,kx);
			}
		}
	}

	string kAns, sAns;
	kAns += (king.x + 'A');
	kAns += ((7 - king.y) + '1');
	sAns += (stone.x + 'A');
	sAns += ((7 - stone.y) + '1');

	cout << kAns << endl;
	cout << sAns << endl;

	return 0;

}