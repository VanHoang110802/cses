#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define int long long

void XuLy()
{
    int a, b; cin >> a >> b;
    int MAX = max(a, b);
    int ans = 0;
    int PowMax = (MAX - 1) * (MAX - 1);
    if(MAX % 2 == 0)
    {
        if(b == MAX)
        {
            ans = PowMax + a;
        }
        else
        {
            ans = PowMax + 2 * MAX - b;
        }
    }
    else
    {
        if(a == MAX)
        {
            ans = PowMax + b;
        }
        else
        {
            ans = PowMax + 2 * MAX - a;
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

    int test;
    cin >> test;
    while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
