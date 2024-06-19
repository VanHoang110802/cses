#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e3 + 5;
const int mod = 1e9 + 7;
int N, numerator, denominator;

int fastpow(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inverse(int a)
{
    return fastpow(a, mod - 2);
}

void XuLy()
{
    cin >> N;
    if(N & 1) cout << "0\n";
    else
    {
        numerator = 1;
        for(int i = 1; i <= N; i++)
        {
            numerator = (numerator * i) % mod;
        }

        denominator = 1;
        for(int i = 1; i <= N/2; i++)
        {
            denominator = (denominator * i) % mod;
        }
        denominator = (denominator * denominator) % mod;
        denominator = (denominator * (N/2+1)) % mod;

        cout << (numerator * inverse(denominator)) % mod;
    }
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
