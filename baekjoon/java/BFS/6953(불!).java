import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Point
{
	private int l;
	private int r;
	private int c;
	private int time;
	
	public Point() 
	{
		
	}
	public Point(int l, int r, int c, int time)
	{
		super();
		this.l = l;
		this.r = r;
		this.c = c;
		this.time = time;
	}
	
	public int getL()
	{
		return l;
	}
	public int getR()
	{
		return r;
	}
	public int getC()
	{
		return c;
	}
	public int getTime()
	{
		return time;
	}	
}

public class Main
{
	static int L, R, C;
	static int[][] dir = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,-1},{0,0,1}}; //상, 하, 북, 남 , 동, 서
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		//가장 빠른 길 찾기
		//동서남북상하
		//1분의 시간을 들여 이동할 수 있다.
		//대각선 불가능
		//지나갈 수 없는 칸 #
		// 비어있는 카 '.'
		while(true)
		{	
			Queue<Point> q = new LinkedList<>();
			String[] input = sc.nextLine().split(" ");
			int L = Integer.parseInt(input[0]);
			int R = Integer.parseInt(input[1]);
			int C = Integer.parseInt(input[2]);
			boolean[][][] visit = new boolean[L][R][C];
			
			StringBuilder[][] building = new StringBuilder[L][R];
			
			if(L == 0 && R == 0 && C == 0)
			{
				System.exit(0);
			}
			
			//3차원 배열 느낌
			for(int l = 0; l < L; l++) //층수
			{
				for(int r =0; r < R; r++)
				{
					String str = sc.nextLine();
					building[l][r] = new StringBuilder(str); // 그 층에 대한 구조
					for(int c = 0; c < C; c++)
					{
						if(building[l][r].charAt(c) == 'S')
						{
							visit[l][r][c] = true;
							q.offer(new Point(l,r,c,0));
						}
					}
				}
				
				String tmp = sc.nextLine();
				
			}
			
			boolean flag = true;
			while(!q.isEmpty())
			{
				int l = q.peek().getL();
				int r = q.peek().getR();
				int c = q.peek().getC();
				int time = q.peek().getTime();
				q.poll();
				if(building[l][r].charAt(c) == 'E')
				{
					System.out.println("Escaped in " + time + " minute(s).");
					flag = false;
					break;
				}
				
				for(int i = 0; i < 6; i++)
				{
					int nl = l + dir[i][0];
					int nr = r + dir[i][1];
					int nc = c + dir[i][2];
					
					if(nl >= 0 && nr >= 0 && nc >= 0 && nl < L && nr < R && nc < C)
					{
						if((building[nl][nr].charAt(nc) == '.' || building[nl][nr].charAt(nc) == 'E') && !visit[nl][nr][nc])
						{
							visit[nl][nr][nc] = true;
							q.offer(new Point(nl,nr,nc,time+1));
						}
					}
				}
			}
			
			if(flag)
			{
				System.out.println("Trapped!");
			}
            q.clear();
		}
	}
}
