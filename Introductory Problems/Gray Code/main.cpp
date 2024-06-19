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
    cin>>n;
    int a[1 << n + 1] = {0};
    for(int i = 0; i < n; i++)
        cout << 0;
    cout << '\n';
    a[0] = 1;
    int x = 0;
    for(int i = 1; i < 1 << n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int y = x ^ (1 << j);
            if (!a[y])
            {
                x = y;
                a[y] = 1;
                string s;
                while(y)
                {
                    if (y & 1) s += '1';
                    else s += '0';
                    y >>= 1;
                }
                reverse(s.begin(), s.end());
                for(int i = 0; i < n - s.size(); i++)
                    cout << 0;
                cout << s <<'\n';
                break;
            }
        }
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
