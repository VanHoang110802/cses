#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define int long long

void XuLy()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int ans1 = i * i;
        int ans2 = ans1 * (ans1 - 1) / 2;
        if(i > 2) ans2 -= 4 * (i - 1) * (i - 2);
        cout << ans2 << '\n';
    }
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
