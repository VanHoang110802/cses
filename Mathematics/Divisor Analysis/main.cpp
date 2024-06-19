#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;

int exp(int x, int y, int m)
{
    int ans = 1;
    x = x % m;
    while(y > 0)
    {
        if(y & 1)
        {
            ans = ans * x % m;
        }
        y = y >> 1;
        x = x * x % m;
    }
    return ans;
}

void XuLy()
{
    int n;
    cin >> n;
    int c[3] = {1, 1, 1};
    int flag = 0;
    int sq = 1, num = 1, d = 1;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        c[0] = c[0] * (y + 1) % mod;
        int gsum = (exp(x, y + 1, mod) - 1 + mod) % mod * exp(x - 1, mod - 2, mod) % mod;
        c[1] = c[1] * gsum % mod;
        sq = sq * exp(x, y / 2, mod) % mod;
        num = num * exp(x, y, mod) % mod;
        if((y & 1) && flag == 0)
        {
            d = d * ((y + 1) / 2) % (mod - 1);
            flag = 1;
        }
        else
        {
            d = d * (y + 1) % (mod - 1);
        }
    }
    //now two cases for product:
    //if all powers are even, then ans = sq^d
    //if at least power is odd, the ans = num^(d/2) [Use Fermat's little theorem]
    if(flag == 1)
    {
        c[2] = exp(num, d, mod);
    }
    else
    {
        c[2] = exp(sq, d, mod);
    }

    cout << c[0] << ' ' << c[1] << ' ' << c[2];
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
