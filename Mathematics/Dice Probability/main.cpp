#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
const int inf = 1LL << 62;

void XuLy()
{
    int n,a,b;
    cin >> n >> a >> b;
    double dp[605][105] = {0};
    dp[0][0] = 1.0;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i < 601; i++)
        {
            for (int k = 1; k < 7; k++)
            {
                if (i - k >= 0)
                {
                    dp[i][j] += dp[i - k][j - 1] * (1.0 / 6);
                }
            }
        }
    }
    double ans = 0;
    for(int i = a; i <= b; i++) ans += dp[i][n];
    cout << fixed << setprecision(6) << ans;
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
