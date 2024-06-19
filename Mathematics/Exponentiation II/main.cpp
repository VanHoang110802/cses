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
const int mod = 1e9 + 7;

int LuyThua(int a, int n, int m)
{
    int ans = 1;
    while(n)
    {
        if(n & 1)
        {
            ans = ans * a % m;
        }
        a = a * a % m;
        n /= 2;
    }
    return ans;
}

void XuLy()
{
    int a, b, c; cin >> a >> b >> c;
    cout << LuyThua(a, LuyThua(b, c, mod - 1), mod) << '\n';
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
