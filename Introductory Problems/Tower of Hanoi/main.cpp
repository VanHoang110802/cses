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

void DeQuy(int a, int b, int c, int n)
{
    if(n == 0) return;
    DeQuy(a, c, b, n - 1);
    cout << a << ' ' << c << '\n';
    DeQuy(b, a, c, n - 1);
}

void XuLy()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    DeQuy(1, 2, 3, n);
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
