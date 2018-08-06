#include<cstdio>
#include<cstring>

char x[1001];
char y[1001];
int d[1001][1001];
int xcnt, ycnt;
int main(void)
{
	for (int i = 0; i < 2; i++)
	{
		char string[1001];
		scanf("%s", string);
		if (i == 0)
		{
			xcnt = 0;
			for (int i = 0; i < strlen(string); i++)
			{
				x[i + 1] = string[i];
				xcnt++;
			}
		}
		else if (i == 1)
		{
			for (int i = 0; i < strlen(string); i++)
			{
				y[i + 1] = string[i];
				ycnt++;
			}
		}
	}

	for (int i = 1; i <= xcnt; i++)
	{
		for (int j = 1; j <= ycnt; j++)
		{
			if (x[i] == y[j])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1];
		}
	}

	printf("%d\n", d[xcnt][ycnt]);

}