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
    int n;
    cin>>n;
    //burnside's lemma: https://youtu.be/D0d9bYZ_qDY
    //no. of objects = avg. no of symmetrical pictures over all symmetries.
    int n0 = n * n;
    int n90 = 1;
    int n180 = 1;
    if(n > 1 && (n & 1))
    {
        n90 = (n + 3) * (n - 1) / 4 - (n - 1) / 2 + 1;
        n180 = (n + 3) * (n - 1) / 2 - (n - 1) + 1;
    }
    else if(n & 1 ^ 1)
    {
        n90 = n * (n + 2) / 4 - n / 2;
        n180 = n * (n + 2) / 2 - n;
    }
    int ans = 0;
    ans = (ans + exp(2, n0, mod)) % mod; //0 deg
    ans = (ans + exp(2, n90, mod)) % mod; //90 deg
    ans = (ans + exp(2, n180, mod)) % mod; //180 deg
    ans = (ans + exp(2, n90, mod)) % mod; //270 deg
    ans = ans * exp(4, mod - 2, mod) % mod;
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
