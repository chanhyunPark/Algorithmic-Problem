import java.awt.*;
import java.util.*;
public class Main
{
	static int M,N;
	static int[][] tomato = new int[1001][1001];
	static int[][] visit = new int[1001][1001];
	static int[] dx = {0,0,1, -1};
	static int[] dy = {1,-1,0,0};

	static void sol()
	{
		Queue<Point> queue = new LinkedList<Point>();
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(tomato[i][j] == 1)
				{
					visit[i][j] = 0;
					queue.offer(new Point(j,i));
				}
			}
		}

		while(!queue.isEmpty())
		{
			int x = queue.peek().x;
			int y = queue.peek().y;
			queue.poll();
			for(int n = 0; n < 4; n++)
			{
				int dirx = x + dx[n];
				int diry = y + dy[n];

				if(dirx >= 0 && dirx < M && diry >= 0 && diry < N)
				{
					if(tomato[diry][dirx] == 0 && visit[diry][dirx] == -1)
					{
						visit[diry][dirx] = visit[y][x] + 1;
						queue.offer(new Point(dirx,diry));
					}
				}
			}
		}
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		M = sc.nextInt();
		N = sc.nextInt();

		for(int m = 0; m < N; m++)
		{
			for(int n = 0; n < M; n++)
			{
				tomato[m][n] = sc.nextInt();
				visit[m][n] = -1;
			}
		}

		sol();
		int max = -1;
		for(int m = 0; m < N; m++)
		{
			for(int n = 0; n < M; n++)
			{
				if(max < visit[m][n])
					max = visit[m][n];
			}
		}
		for(int m = 0; m < N; m++)
		{
			for(int n = 0; n < M; n++)
			{
				if(tomato[m][n] == 0 && visit[m][n] == -1)
					max = -1;
			}
		}

		System.out.println(max);
	}
}
