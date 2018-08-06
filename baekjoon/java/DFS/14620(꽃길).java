import java.util.Scanner;

public class Main {

   static int min = 987654321;
   static int[][] cost;
   static boolean[][] visit = new boolean[11][11];
   static int[][] dir = {{0,0}, {0,1}, {0,-1}, {-1,0}, {1,0}};
   static int N;
   public static void main(String[] args) {

      Scanner sc = new Scanner(System.in);
      N = sc.nextInt(); //
      cost = new int[N][N];
      for(int n = 0; n < N; n++)
      {
         for(int m = 0; m < N; m++)
         {
            cost[n][m] = sc.nextInt();
         }
      }

      dfs(1,1,0,0);

      System.out.println(min);
   }

   static boolean flower(int y, int x)
   {
      for(int i = 0; i < 5; i++)
      {
         if(visit[y + dir[i][0]][x + dir[i][1]])
            return false;
      }
      return true;
   }

   static void dfs(int y, int x, int sum, int cnt)
   {
      if(cnt == 3)
      {
         min = Math.min(min,sum);
         return;
      }

      if(x >= N - 1)
      {
         x = 1;
         y++;
      }

      if(y >= N - 1)
         return;

      if(flower(y,x))
      {
         int tmp = sum;
         for(int i = 0; i < 5; i++)
         {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            visit[ny][nx] = true;
            sum += cost[ny][nx];
         }
         dfs(y, x+3, sum, cnt+1);
         for(int i = 0; i < 5; i++)
            visit[y+dir[i][0]][x+dir[i][1]] = false;
         sum = tmp;
      }
      dfs(y, x+1, sum, cnt);
   }
}