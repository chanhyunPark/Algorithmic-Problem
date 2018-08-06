#include<iostream>

using namespace std;

int N;
int kim, im;
int main(void)
{
	cin >> N;
	cin >> kim >> im;
	int ans = 0;
	while (true)
	{
		if (kim == 0 || im == 0)
		{
			ans = -1;
			break;
		}
		if (kim == im)
		{
			cout << ans << '\n';
			return 0;
		}
		int modK = kim % 2;
		int modI = im % 2;
		if (modK == 0)
			kim /= 2;
		else
			kim = (kim / 2) + 1;

		if (modI == 0)
			im /= 2;
		else
			im = (im / 2) + 1;
		
		ans++;
	}
	cout << ans << endl;
	return 0;
}