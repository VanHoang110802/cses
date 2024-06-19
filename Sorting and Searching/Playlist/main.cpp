#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int a[MAXN];
map<int, int> MAP;
int n;

void XuLy()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for(int i = 0, j = 0; i < n; ++i)
    {
        while(j < n && MAP[a[j]] < 1)
        {
            MAP[a[j]]++;
            ++j;
        }
        ans = max(ans, j - i);
        MAP[a[i]]--;
    }
    cout << ans;
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
