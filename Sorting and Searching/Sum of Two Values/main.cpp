#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
map<int, int> MAP;
int n, k;

void XuLy()
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        if(MAP.find(k - x) != MAP.end())
        {
            cout << MAP[k - x] + 1 << ' ' << i + 1 << '\n';
            return;
        }
        MAP[x] = i;
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
