#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;

int DeQuy(int n, int k)
{
    if(n == 1)
    {
        return 1;
    }
    if(k <= (n + 1) / 2)
    {
        if(2 * k > n) return 2 * k % n;
        else return 2 * k;
    }

    int c = DeQuy(n >> 1, k - (n + 1) / 2);
    if(n & 1) return 2 * c + 1;
    else return 2 * c - 1;
}

void XuLy()
{
    int n, k;
    cin >> n >> k;
    cout << DeQuy(n, k)<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test;
    cin >> test;
    while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
