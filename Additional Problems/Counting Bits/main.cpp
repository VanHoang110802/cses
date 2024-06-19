#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
const int inf = 1LL << 62;

int N;
map<int, int> dp;

int f(int a)
{
    if(a == 0) return 0;
    if(dp[a]) return dp[a];
    if(a & 1) return dp[a] = 2 * f(a / 2) + (a / 2) + 1;
    else return dp[a] = f(a / 2) + f(a / 2 - 1) + (a / 2);
}

void XuLy()
{
    int n;
    cin >> n;
    cout << f(n);
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
