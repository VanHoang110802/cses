#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1 << 60;
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
int fac[MAXN], inv[MAXN];

int exp(int x, unsigned int y, int m)
{
    int res = 1;
    x = x % m;
    while(y > 0)
    {
        if(y & 1) res = (res * x) % m;
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}

void F()
{
    fac[0] = 1, inv[0] = 1;
    for(int i = 1; i < MAXN; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = exp(fac[i], mod - 2, mod);
    }
}

void XuLy()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 2; i < n + 1; ++i)
    {
        if(i % 2 == 0) (ans += inv[i]) %= mod;
        else ans = (ans - inv[i] + mod) % mod;
    }
    (ans *= fac[n]) %= mod;
    cout << ans;
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
    F();
    XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
