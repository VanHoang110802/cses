#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int c[MAXN];
int n;

void XuLy()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        c[x]++;
    }
    for(int i = MAXN; i; --i)
    {
        int d = 0;
        for(int j = i; j <= MAXN; j += i)
        {
            d += c[j];
        }
        if(d > 1)
        {
            cout << i;
            return;
        }
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
