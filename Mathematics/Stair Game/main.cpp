#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;
const int inf = 1LL << 62;
int a[MAXN];

void XuLy()
{
    int n;
    cin>>n;
    //even positions do not contribute
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i & 1) x ^= a[i];
    }
    if(x) cout << "first\n";
    else cout << "second\n";
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
