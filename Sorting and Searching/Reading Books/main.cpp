#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int a[MAXN];
int n;

void XuLy()
{
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    cout << max(sum, 2 * a[n - 1]);
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
