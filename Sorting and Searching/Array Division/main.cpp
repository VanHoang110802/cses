#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>
#include <map>
using namespace std;

#define int long long
const int MAXN = 3 * 1e5;
const int MAXX = 1e18;
int a[MAXN];
int n, k;

void XuLy()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int l = 0, r = MAXX;
    int ans = 0;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        int s = MAXX + 7;
        int num = 0;
        bool Check = true;
        for(int i = 1; i <= n; ++i)
        {
            if(a[i] > m)
            {
                Check = false;
                break;
            }
            if(s + a[i] <= m)
            {
                s += a[i];
            }
            else
            {
                s = a[i];
                num++;
            }
        }
        if(Check == false || num > k)
        {
            l = m;
        }
        else
        {
            ans = m;
            r = m;
        }
    }
    cout << ans << '\n';
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
