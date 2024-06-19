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
int s[MAXN];
int n;

void dfs(int u = 0, int p = -1)
{
    s[u] = 1;
    for(auto v : adj[u])
    {
        dfs(v, u);
        s[u] += s[v];
    }
}

void XuLy()
{
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int x; cin >> x;
        --x;
        adj[x].push_back(i);
    }
    dfs();
    for(int i = 0; i < n; ++i) cout << s[i] - 1 << ' ';
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
