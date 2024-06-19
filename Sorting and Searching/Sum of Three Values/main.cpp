#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
using namespace std;

#define int long long
const int MAXN = 5e3 + 7;
array<int, 2> a[MAXN];
int n, k;

void XuLy()
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; ++i)
    {
        int x = k - a[i][0];
        for(int j = i + 1, temp = n - 1; j < temp; ++j)
        {
            while(j < temp && a[j][0] + a[temp][0] > x)
            {
                --temp;
            }
            if(j < temp && a[j][0] + a[temp][0] == x)
            {
                cout << a[i][1] + 1 << ' ' << a[j][1] + 1 << ' ' << a[temp][1] + 1;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
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
