#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <functional>
#include <queue>
#include <stack>
#include <array>
#include <list>
using namespace std;

#define int long long
const int mxN = 2e5+5;
int dp[mxN];

void XuLy()
{
    int n;
    cin >> n;
    int a[n + 1] = {0};
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(dp[i - 1] < a[i])
        {
            cout << dp[i - 1];
            return;
        }
        dp[i] = dp[i - 1] + a[i];
    }
    cout << dp[n];
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
