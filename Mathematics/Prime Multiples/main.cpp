#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1LL<<60;
const int MAXN = 27;
int a[MAXN];

void XuLy()
{
    int n, k;
    cin >> n >> k;
    //inclusion-exclusion
    int ans = 0;

    for(int i = 0; i < k; ++i) cin >> a[i];

    for(int i = 1; i < 1 << k; ++i)
    {
        int x = -1;
        if(__builtin_popcount(i) & 1) x = 1;
        int y = n;
        int z = 1;
        for(int j = 0; j < k; j++)
        {
            if(i >> j & 1)
            {
                if(z >= n / a[j] + 1)
                {
                    z = INF;
                    break;
                }
                z = z * a[j];
            }
        }
        y /= z;
        ans += x * y;
    }
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
