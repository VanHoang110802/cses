#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
using namespace std;

#define int long long
const int MAXN = 5e2;
const int mod = 1e9 + 7;
int dp[MAXN * (MAXN + 1) / 2 + 7];
int n;

void XuLy()
{
    cin >> n;
    int s = n * (n + 1) / 2;
    if(s & 1)
    {
        cout << 0;
        return;
    }
    s /= 2;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i * (i + 1) / 2; j >= i; --j)
        {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[s] * ((mod + 1) / 2) % mod;
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
