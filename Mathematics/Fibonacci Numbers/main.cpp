#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1 << 60;
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
int fac[MAXN], inv[MAXN];

pair<int, int> fib(int n, int m)
{
    if(n == 0)
    {
        return {0, 1};
    }
    auto p = fib(n >> 1, m);
    int c = (int)p.first * (2 * (int)p.second - (int)p.first + m) % m;
    int d = ((int)p.first * (int)p.first % m + (int)p.second * (int)p.second % m) % m;
    if(n & 1) return {d, (c + d) % m};
    else return {c, d};
}

void XuLy()
{
    int n; cin >> n;
    cout << fib(n, mod).first;
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
