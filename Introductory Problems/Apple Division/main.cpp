#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define int long long
const int MAXN = 20;
int a[MAXN];

void XuLy()
{
    int n; cin >> n;
    int sum = 0, ans = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < 1 << n; ++i)
    {
        int cs = 0;
        for(int j = 0 ; j < n; ++j)
        {
            if(i >> j & 1)
            {
                cs += a[j];
            }
        }
        if(cs <= sum / 2)
        {
            ans = max(ans, cs);
        }
    }
    cout << sum - 2 * ans;
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
