#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

typedef struct Dragon
{
   int x; //y좌표
   int y; //x좌표
   int d; //방향
   int g; //세대

public:
   Dragon() {}
   Dragon(int x, int y, int d, int g) : y(y), x(x), d(d), g(g) {}

};
void Print();
vector<Dragon> v;
int map[200][200];
int dir[4][2] = { { 0,1 },{ -1,0 },{ 0,-1 },{ 1,0 } };
int main(void)
{
   int N;
   cin >> N;
   for (int n = 0; n < N; n++)
   {
      int x, y, d, g;
      cin >> x >> y >> d >> g;
      v.push_back(Dragon(x, y, d, g));
      map[y][x] = 1;
   }
   
   for (int n = 0; n < N; n++)
   {
      int gnr = v[n].g;
      int di = v[n].d;
      int y = v[n].y;
      int x = v[n].x;
      stack<Dragon> s;
      stack<Dragon> tmp;
      s.push(Dragon(x, y, di, 0)); //좌표, 방향, 세대
      s.push(Dragon(x + dir[di][1], y + dir[di][0], di, 0));
      map[y + dir[di][0]][x + dir[di][1]] = 1;
      tmp = s;
      for (int i = 0; i < gnr; i++)
      {
         int cy = s.top().y;
         int cx = s.top().x;
         for (int j = 0; j < pow(2,i); j++)
         {
            Dragon dr = s.top();
            s.pop();
            int d = (dr.d + 1) % 4;
            cy += dir[d][0];
            cx += dir[d][1];
            tmp.push(Dragon(cx, cy, d, i+1));
            map[cy][cx] = 1;
         }
         s = tmp;
      }
   }

   int ans = 0;
   for (int i = 0; i <= 99; i++)
   {
      for (int j = 0; j <= 99; j++)
      {
         if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1 && map[i][j + 1] == 1)
            ans++;
      }
   }

   cout << ans << '\n';
   return 0;
}
