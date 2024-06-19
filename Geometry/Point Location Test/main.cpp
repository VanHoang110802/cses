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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int cp = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if(cp < 0) cout << "RIGHT\n";
    if(cp > 0) cout << "LEFT\n";
    if(cp == 0) cout << "TOUCH\n";
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
