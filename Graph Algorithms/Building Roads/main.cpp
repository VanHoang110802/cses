#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <functional>
#include <queue>
#include <stack>
#include <array>
#include <list>
#include <vector>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN], ans;
bool visited[MAXN];
int n, m;

void dfs(int u)
{
    visited[u] = true;
    for(auto v : adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

void XuLy()
{
    cin >> n >> m;
    for(int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; ++i)
    {
        if(!visited[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << '\n';
    for(int i = 1; i < ans.size(); ++i)
    {
        cout << ans[0] + 1 << ' ' << ans[i] + 1 << ' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

//    int test;
//    cin >> test;
//    while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
