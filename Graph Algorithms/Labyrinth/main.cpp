#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
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

#define int long long
const int MAXN = 1e3 + 7;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};
string s[MAXN], p[MAXN];
int d[MAXN][MAXN];
int n, m, si, sj, ti, tj;

bool Check(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.');
}

void XuLy()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> s[i];
        for(int j = 0; j < m; ++j)
        {
            if(s[i][j] == 'A')
            {
                si = i;
                sj = j;
                //s[i][j] = '.';
            }
            if(s[i][j] == 'B')
            {
                ti = i;
                tj = j;
                s[i][j] = '.';
            }
        }
        p[i] = string(m, 0);
    }
    queue<array<int, 2> > qu;
    qu.push({si, sj});
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
            s[ni][nj] = '#';
            d[ni][nj] = k;
            p[ni][nj] = dc[k];
        }
    }
    if(p[ti][tj])
    {
        cout << "YES\n";
        string temp;
        while(ti ^ si || tj ^ sj)
        {
            temp += p[ti][tj];
            int temp_d = d[ti][tj] ^ 2;
            ti += di[temp_d];
            tj += dj[temp_d];
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
