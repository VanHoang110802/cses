#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
int iv[MAXN], f1[MAXN], f2[MAXN];

void F()
{
    iv[1] = 1;
    for(int i = 2; i <= MAXN; ++i)
    {
        iv[i] = mod - mod / i * iv[mod % i] % mod;
    }
    f1[0] = f2[0] = 1;
    for(int i = 1; i <= MAXN; ++i)
    {
        f1[i] = f1[i - 1] * i % mod;
        f2[i] = f2[i - 1] * iv[i] % mod;
    }
}

void XuLy()
{
    int a, b; cin >> a >> b;
    cout << f1[a] * f2[b] % mod * f2[a - b] % mod << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    F();
    int test;
    cin >> test;
    while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
