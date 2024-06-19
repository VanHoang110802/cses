#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
const int inf = 1LL << 62;

void XuLy()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x & 1) ans = 1;
    }
    cout << (ans ? "first\n" : "second\n");
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
