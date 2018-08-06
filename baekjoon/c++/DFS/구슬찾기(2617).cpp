#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> bV[100];
int big[100];
int small[100];
int visit[100];
int cnt = 0;
void Dfs(int idx) 
{
    for (int i = 0; i < bV[idx].size(); i++)
    {
        if (!visit[bV[idx][i]])
        {
            cnt++;
            visit[bV[idx][i]] = true;
            big[bV[idx][i]]++;
            Dfs(bV[idx][i]);
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for (int m = 0; m < M; m++)
    {
        int b, s;
        cin >> b >> s;
        bV[b].push_back(s);
    }

    int ans = 0;
    int mid = (1 + N) / 2;
    for (int i = 1; i <= N; i++)
    {
        memset(visit,false, sizeof(visit));
        
        Dfs(i);
        small[i] = cnt;
        cnt = 0;
    }

    for (int n = 1; n <= N; n++)
    {
        if (small[n] >= mid || big[n] >= mid)
            ans++;
    }


    cout << ans << endl;

    return 0;
}