#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <array>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int n;

void XuLy()
{
    cin >> n;
    set<array<int, 2> > SET;
    for(int i = 0; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        SET.insert({2 * x, 1});
        SET.insert({2 * y + 1, -1});
    }
    int ans = 0, c = 0;
    for(array<int, 2> a : SET)
    {
        c += a[1];
        ans = max(ans, c);
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
