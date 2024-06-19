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

void XuLy()
{
    int n;
    cin >> n;
    int a = 1, b = 0;
    while(n > 0)
    {
        for(int i = 2; i <= n; i += 2)
        {
            cout << a * i + b << ' ';
        }
        if(n & 1)
        {
            cout << a + b << ' ';
            b += a;
        }
        else
        {
            b -= a;
        }
        a <<= 1;
        n >>= 1;
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
