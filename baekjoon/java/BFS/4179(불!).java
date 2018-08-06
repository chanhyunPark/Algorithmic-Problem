import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Jihun
{
	private int y;
	private int x;
	private char type;
	private int cnt;
	
	public Jihun() 
	{
		
	}
	public Jihun(int y, int x, char type, int cnt)
	{
		super();
		this.y = y;
		this.x = x;
		this.type = type;
		this.cnt = cnt;
	}
	public int getY()
	{
		return y;
	}
	public int getX()
	{
		return x;
	}
	public char getType()
	{
		return type;
	}
	public int getCnt()
	{
		return cnt;
	}
}
public class Main
{
	static int[][] dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		int R = Integer.parseInt(input.split(" ")[0]);
		int C = Integer.parseInt(input.split(" ")[1]);
		Queue<Jihun> q = new LinkedList<>();
		StringBuilder[] str = new StringBuilder[R];
		boolean[][] visit = new boolean[R][C];
		int startx = 0, starty = 0;
		for(int r = 0; r < R; r++)
		{
			String tmp = sc.nextLine().toString();
			str[r] = new StringBuilder(tmp);
			for(int c = 0; c < C; c++)
			{
				if(str[r].charAt(c) == 'J')
				{
					starty = r;
					startx = c;
					visit[r][c] = true;
				}
				else if (str[r].charAt(c) == 'F')
				{
					q.offer(new Jihun(r,c,'F',0));
				}		
			}
		}
		
		q.offer(new Jihun(starty, startx,'J',0));
		while(!q.isEmpty())
		{
			int y = q.peek().getY();
			int x = q.peek().getX();
			int cnt = q.peek().getCnt();
			int type = q.peek().getType();
			q.poll();
			
			if(type == 'J')
			{
				if(y == 0 || x == 0 || y == R-1 || x == C-1)
				{
					System.out.println(cnt+1);
					System.exit(0);
				}
			}
			
			if(type == 'F')
			{
				for(int i = 0; i < 4; i++)
				{
					int ny = y + dir[i][0];
					int nx = x + dir[i][1];
					if(ny >= 0 && nx >= 0 && ny < R && nx < C)
					{
						if(str[ny].charAt(nx) == '.')
						{
							str[ny].setCharAt(nx, 'F');
							q.offer(new Jihun(ny, nx,'F', cnt));
						}
						
					}
				}
			}
			else if(type == 'J')
			{
				for(int i = 0; i < 4; i++)
				{
					int ny = y + dir[i][0];
					int nx = x + dir[i][1];
					if(ny >= 0 && nx >= 0 && ny < R && nx < C)
					{
						if(str[ny].charAt(nx) == '.' && !visit[ny][nx])
						{
							visit[ny][nx] = true;
							q.offer(new Jihun(ny, nx,'J', cnt+1));
						}
						
					}
				}
				
			}
			
		}
		System.out.println("IMPOSSIBLE");
	}
}
