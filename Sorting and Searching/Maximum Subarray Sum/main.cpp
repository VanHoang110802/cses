#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define int long long
int n;

void XuLy()
{
    cin >> n;
    int ans = -1e18, msf = -1e18;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        msf = max(x, msf + x);
        ans = max(ans, msf);
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
