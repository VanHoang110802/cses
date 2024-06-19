#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <array>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int n, m;

void XuLy()
{
    cin >> n >> m;
    set<array<int, 2> > SET;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        SET.insert({x, i});
    }
    for(int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        auto it = SET.lower_bound({x + 1, 0});
        if(it == SET.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            --it;
            cout << (*it)[0] << '\n';
            SET.erase(it);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //int test;
    //cin >> test;
    //while(test--)
        XuLy();

    //cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
