#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 987654321

bool day[200];
int   dp[200][200];
int N, M;
int minValue = MAX;
int Dfs(int cnt, int coupon) 
{
   if (cnt > N)
   {
      return 0;
   }

   int &ret = dp[cnt][coupon];

   if (ret != -1)
      return ret;

   ret = MAX;

   if (day[cnt])
   {
      ret = min(ret, Dfs(cnt + 5, coupon + 2) + 37000);
      ret = min(ret, Dfs(cnt + 3, coupon + 1) + 25000 );
      if (coupon >= 3)
         ret = min(ret, Dfs(cnt + 1, coupon - 3));
      else
         ret = min(ret, Dfs(cnt + 1, coupon) + 10000);
   }
   else
      ret = min(ret, Dfs(cnt + 1, coupon));

   return ret;
}

int main(void)
{
   memset(day, true, sizeof(day));
   memset(dp, -1, sizeof(dp));
   
   cin >> N >> M;

   for (int m = 0; m < M; m++)
   {
      int num;
      cin >> num;
      day[num] = false;
   }

   int ans = Dfs(1, 0);

   cout << ans << "\n";
   return 0;
}