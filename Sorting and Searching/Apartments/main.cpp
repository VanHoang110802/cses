#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int a[MAXN], b[MAXN];
int n, m, k;

void XuLy()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    for(int i = 0, j = 0; i < n; ++i)
    {
        while(j < m && b[j] < a[i] - k)
        {
            ++j;
        }
        if(j < m && b[j] <= a[i] + k)
        {
            ++ans;
            ++j;
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
