int check() 
{
	int pass = 0;
	memset(ck, false, sizeof(ck));

	for (int w = 0; w < W; w++)
	{
		int cnt = 0;
		for (int d = 0; d < D; d++)
		{
			if (tmp[d][w] == 0)
			{
				++cnt;
				if (cnt == K)
				{
					pass += 1;
					ck[w] = true;
					break;
				}
			}
			else
			{
				if (cnt >= K)
				{
					pass += 1;
					ck[w] = true;
					break;
				}
				else
					cnt = 0;
			}
		}
	}

	for (int w = 0; w < W; w++)
	{
		if (!ck[w])
		{
			int cnt = 0;
			for (int d = 0; d < D; d++)
			{
				if (tmp[d][w] == 1)
				{
					++cnt;
					if (cnt == K)
					{
						pass += 1;
						break;
					}
				}
				else
				{
					if (cnt >= K)
					{
						pass += 1;
						break;
					}
					else
						cnt = 0;
				}
			}
		}
	}
	return pass;
}