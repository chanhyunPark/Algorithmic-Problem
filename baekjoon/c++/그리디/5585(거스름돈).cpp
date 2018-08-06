#include<iostream>

using namespace std;

int main(void)
{
   int coin[6] = {500, 100, 50, 10, 5, 1};
   int n;
   cin >> n;
   int sub = 1000 - n;

   int count = 1;
   int ans = 0;
   for (int i = 0; i < 6; i++)
   {
      if (sub == 0)
         break;

      while (1)
      {
         if (sub > coin[i] * count)
            count++;
         else if (sub == coin[i] * count)
         {
            sub -= (coin[i] * count);
            ans += count;
            break;
         }
         else if (sub < coin[i] * count)
         {
            sub -= (coin[i] * (count - 1));
            ans += (count - 1);
            break;
         }
         else
         {
            break;
         }
      }
      count = 1;
   }
   cout << ans << endl;
}