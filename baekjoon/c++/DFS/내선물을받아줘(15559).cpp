#include<iostream>
#include<string>
using namespace std;
 
int n, m, ans;
char map[1001][1001];
bool chk[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y)
{
    chk[x][y] = true;
 
 
    //현재 지점에서 움직일 수 있는 좌표
    int nx, ny;
    if (map[x][y] == 'S')
    {
        nx = x + 1;
        ny = y;
    }
    else if (map[x][y] == 'N')
    {
        nx = x - 1;
        ny = y;
    }
    else if (map[x][y] == 'E')
    {
        nx = x;
        ny = y + 1;
    }
    else if (map[x][y] == 'W')
    {
        nx = x;
        ny = y - 1;
    }
 
    if (nx >= 0 && ny >= 0 && nx < n && ny < m && !chk[nx][ny])
    {
        dfs(nx, ny);
    }
 
 
    //현재지점으로 올 수 있는 좌표
    for (int d = 0; d < 4; d++)
    {
        nx = x + dx[d];
        ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !chk[nx][ny])
        {
            if (map[nx][ny] == 'S' && d == 3)
            {
                dfs(nx, ny);
            }
            else if (map[nx][ny] == 'N' && d == 2)
            {
                dfs(nx, ny);
            }
            else if (map[nx][ny] == 'E' && d == 1)
            {
                dfs(nx, ny);
            }
            else if (map[nx][ny] == 'W' && d == 0)
            {
                dfs(nx, ny);
            }
        }
    }
 
}
int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!chk[i][j])
            {
                ans++;
                dfs(i, j);
            }
        }
    }
 
    cout << ans;
    
    return 0;
}