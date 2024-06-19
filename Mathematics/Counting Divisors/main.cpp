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
#define se second
#define fi first
const int MAXN = 1e6 + 7;
int a[MAXN];
vector<int> v;

void Sang()
{
    for(int i = 2; i <= MAXN; ++i)
    {
        if(!a[i])
        {
            v.push_back(i);
            a[i] = i;
        }
        for(int j = 0; j < v.size() && v[j] <= a[i] && i * v[j] <= MAXN; ++j)
        {
            a[i * v[j]] = v[j];
        }
    }
}

void XuLy()
{
    map<int, int> MAP;
    int x; cin >> x;
    while(x > 1)
    {
        MAP[a[x]]++;
        x /= a[x];
    }
    int ans = 1;
    for(auto i : MAP)
    {
        ans *= (i.se + 1);
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Sang();
    int test;
    cin >> test;
    while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
