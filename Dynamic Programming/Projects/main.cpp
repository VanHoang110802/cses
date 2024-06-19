#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <vector>
#include <set>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
array<int, 3> a[MAXN];
int n;

void XuLy()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    sort(a, a + n);
    set<array<int, 2> > dp;
    dp.insert({0, 0});
    int temp_dp = 0;
    for(int i = 0; i < n; ++i)
    {
        auto it = dp.lower_bound({a[i][1]});
        --it;
        temp_dp = max(temp_dp, (*it)[1] + a[i][2]);
        dp.insert({a[i][0], temp_dp});
    }
    cout << temp_dp;
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
