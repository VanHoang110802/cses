#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <vector>
#include <set>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int dp0[MAXN], dp1[MAXN];
int n;

void dfs(int u = 0, int p = -1)
{
    for(auto v : adj[u])
    {
        if(v == p)
        {
            continue;
        }
        dfs(v, u);
        dp1[u] = max(dp1[u] + max(dp0[v], dp1[v]), dp0[u] + dp0[v] + 1);
        dp0[u] += max(dp0[v], dp1[v]);
    }
}

void XuLy()
{
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    cout << max(dp0[0], dp1[0]);
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
