#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <array>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
array<int, 2> a[MAXN];
int n;

void XuLy()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i][1] >> a[i][0];
    }
    sort(a, a + n);
    int ans = 0, MAX = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i][1] >= MAX)
        {
            ++ans;
            MAX = a[i][0];
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
