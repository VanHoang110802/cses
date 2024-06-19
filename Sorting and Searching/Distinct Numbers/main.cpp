#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
long long a[MAXN];
int n;

void XuLy()
{
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    cout << mp.size();
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
