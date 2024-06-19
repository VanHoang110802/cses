#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
array<int, 2> a[MAXN];
int n;

void XuLy()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
    sort(a, a + n);
    int t = 0, ans = 0;
    for(int i = 0; i < n; ++i)
    {
        t += a[i][0];
        ans += a[i][1] - t;
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

    //int test;
    //cin >> test;
    //while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
