#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
int c[MAXN];
int n, ans = 0;

int TempSum(int temp)
{
    return (temp % mod * ((temp - 1) % mod) % mod * ((mod + 1) / 2) % mod);
}

void XuLy()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int temp = n / (n / i);
        ans += n / i % mod * (TempSum(temp + 1) - TempSum(i) + mod) % mod;
        i = temp;
    }
    cout << ans % mod;
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
