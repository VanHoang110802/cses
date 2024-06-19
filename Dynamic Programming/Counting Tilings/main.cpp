#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e4 + 7;
const int mod = 1e9 + 7;
int dp[MAXN][MAXN];
int n, m;

void DeQuy(int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
    if(x == n) return;
    if(y >= m) (dp[x + 1][next_mask] += dp[x][mask]) %= mod;
    else
    {
        int my_mask = 1 << y;
        if(mask & my_mask) DeQuy(x, y + 1, mask, next_mask);
        else
        {
            DeQuy(x, y + 1, mask, next_mask | my_mask);
            if(y + 1 < m && ! (mask & (my_mask << 1))) DeQuy(x, y + 2, mask, next_mask);
        }
    }
}

void XuLy()
{
    cin >> m >> n;
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (1 << m); j++)
        {
            DeQuy(i, 0, j, 0);
        }
    }
    cout << dp[n][0];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //int test;
    //cin >> test;
    //while(test--)
    XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
