#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;

int exp(int x, int y, int m)
{
    int ans = 1;
    x = x % m;
    while(y > 0)
    {
        if(y & 1)
            ans = ans * x % m;
        y = y >> 1;
        x = x * x % m;
    }
    return ans;
}

void XuLy()
{
    int n, m;
    cin >> n >> m;
    //burnside's lemma
    //no. of objects = avg. no of symmetrical pictures over all symmetries.
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = (ans + exp(m, __gcd(i, n), mod)) % mod;
    }
    ans = ans * exp(n, mod - 2, mod) % mod;
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
    XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
