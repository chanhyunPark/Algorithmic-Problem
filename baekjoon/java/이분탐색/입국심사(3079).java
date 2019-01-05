import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main
{
	static long N, M;
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();

		String [] tmp = input.split(" ");
		N = Long.parseLong(tmp[0]); // 입국 심사 대
		M = Long.parseLong(tmp[1]); // 인원 수

		long [] time = new long[(int)(N + 1)];


		long minValue = Long.MAX_VALUE;
		long maxValue = Long.MIN_VALUE;
		for(int n = 0; n < N; n++)
		{
			time[n] = Long.parseLong(br.readLine()); //n번째에 걸리는 시간
			minValue = Math.min(minValue, time[n]);
			maxValue = Math.max(maxValue, time[n]);
		}

		long left = 0;
		long right = maxValue * M;
		long mid = 0;
		long ans = right;
		while(left <= right)
		{
			mid = (left + right) / 2;
			long cnt = 0; // 내가 세본 사람 수
			for(int n = 0; n < N; n++)
			{
				cnt += (mid / time[n]);
			}

			if(cnt < M)
			{
				left = mid + 1;
			}
			else if(cnt >= M)
				right = mid - 1;

			cnt = 0;
		}

		System.out.println(left);
	}
}
