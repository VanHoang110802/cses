#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <functional>
#include <queue>
#include <stack>
#include <array>
#include <list>
using namespace std;

//#define int long long
const int MAXN = 1e3 + 7;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};
string s[MAXN];
bool visited[MAXN][MAXN];
int d1[MAXN][MAXN], d2[MAXN][MAXN], p1[MAXN][MAXN], p2[MAXN][MAXN];
int n, m, si, sj;

bool Check(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.' && !visited[i][j]);
}

void bfs(vector<array<int, 2> > v, int d[MAXN][MAXN], int p[MAXN][MAXN])
{
    queue<array<int, 2> > qu;
    memset(visited, false, sizeof(visited));
    memset(d, 0x3f, sizeof(d2)); // 0x3f
    for(array<int, 2> a : v)
    {
        qu.push(a);
        visited[a[0]][a[1]] = true;
        d[a[0]][a[1]] = true;
    }
    while(qu.size())
    {
        array<int, 2> u = qu.front();
        qu.pop();
        for(int k = 0; k < 4; ++k)
        {
            int ni = u[0] + di[k];
            int nj = u[1] + dj[k];
            if(!Check(ni, nj))
            {
                continue;
            }
            qu.push({ni, nj});
            visited[ni][nj] = true;
            d[ni][nj] = d[u[0]][u[1]] + 1;
            p[ni][nj] = k;
        }
    }
}

void XuLy()
{
    cin >> n >> m;
    vector<array<int, 2> > v2;
    for(int i = 0; i < n; ++i)
    {
        cin >> s[i];
        for(int j = 0; j < m; ++j)
        {
            if(s[i][j] == 'A')
            {
                si = i;
                sj = j;
                s[i][j] = '.';
            }
            if(s[i][j] == 'M')
            {
                v2.push_back({i, j});
                s[i][j] = '.';
            }
        }
        //p[i] = string(m, 0);
    }
    bfs({{si, sj}}, d1, p1);
    bfs(v2, d2, p2);
    int ti = -1, tj;
    for(int i = 0; i < n; ++i)
    {
        // (i, 0) (i, m - 1)
        if(d1[i][0] < d2[i][0])
        {
            ti = i;
            tj = 0;
        }
        if(d1[i][m - 1] < d2[i][m - 1])
        {
            ti = i;
            tj = m - 1;
        }
    }
    for(int j = 0; j < m; ++j)
    {
        // (0, j) (n - 1, j)
        if(d1[0][j] < d2[0][j])
        {
            ti = 0;
            tj = j;
        }
        if(d1[n - 1][j] < d2[n - 1][j])
        {
            ti = n - 1;
            tj = j;
        }
    }
    if(~ti)
    {
        cout << "YES\n";
        string temp;
        while(ti ^ si || tj ^ sj)
        {
            temp += dc[p1[ti][tj]];
            int temp_dc = p1[ti][tj] ^ 2;
            ti += di[temp_dc];
            tj += dj[temp_dc];
        }
        reverse(temp.begin(), temp.end());
        cout << temp.size() << '\n' << temp;
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

//    int test;
//    cin >> test;
//    while(test--)
    XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
