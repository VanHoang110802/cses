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
#define X first
#define Y second

void XuLy()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
    int ans = 0;
    for(int i = 0; i < n; i ++)
    {
        ans += (a[i].X * a[(i + 1) % n].Y - a[(i + 1) % n].X * a[i].Y);
    }
    cout << abs(ans);
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
