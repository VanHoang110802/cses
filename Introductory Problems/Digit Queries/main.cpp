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

int xpow(int x, unsigned int y)
{
    int res = 1;
    while(y > 0)
    {
        if (y & 1) res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

void XuLy()
{
    int n;
    cin>>n;
    int c = 1;
    for (int p = 9; ; n -= p, c++, p = 9 * xpow(10, c - 1) * c)
    {
        if (n - p <= 0) break;
    }
    n--;
    int x = n / c;
    int y = n % c;
    int ans = xpow(10, c - 1) + x;
    string s = to_string(ans);
    cout << s[y] << '\n';
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
