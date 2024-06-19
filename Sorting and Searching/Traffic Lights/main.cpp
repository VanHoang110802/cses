#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int a[MAXN];
map<int, int> MAP;
int x, n;

void XuLy()
{
    cin >> x >> n;
    set<int> SET;
    SET.insert(0);
    SET.insert(x);
    MAP[x] = 1;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        auto it = SET.lower_bound(a[i]);
        int temp2 = *it;
        --it;
        int temp = *it;
        --MAP[temp2 - temp];
        if(!MAP[temp2 - temp])
        {
            MAP.erase(temp2 - temp);
        }
        SET.insert(a[i]);
        ++MAP[temp2 - a[i]];
        ++MAP[a[i] - temp];
        cout << ((--MAP.end())->first) << ' ';
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
