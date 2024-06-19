#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
int a[MAXN];

void XuLy()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<int, int> dp[1 << n];
    dp[0] = {0, k + 1};
    for (int s = 1; s < (1<<n); s++)
    {
        dp[s] = {25, 0};
        for (int i = 0; i < n; i++)
        {
            if (s >> i & 1)
            {
                auto [c, w] = dp[s ^ (1 << i)];
                if (w + a[i] > k)
                {
                    c++;
                    w = min(a[i], w);
                }
                else
                {
                    w += a[i];
                }
                dp[s] = min(dp[s], {c, w});
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
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
