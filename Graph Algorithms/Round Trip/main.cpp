#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
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

//#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN], ans;
int c[MAXN];
bool visited[MAXN];
int n, m;

void dfs(int u, int temp = -1)
{
    c[u] = temp;
    visited[u] = true;
    for(auto v : adj[u])
    {
        if(v == temp)
        {
            continue;
        }
        if(visited[v])
        {
            int temp_u = u;
            while(u ^ v)
            {
                ans.push_back(u);
                u = c[u];
            }
            ans.push_back(v);
            ans.push_back(temp_u);
            cout << ans.size() << '\n';
            for(auto i : ans) cout << i + 1 << ' ';
            exit(0);
        }
        else
        {
            dfs(v, u);
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
            dfs(i);
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

//    int test;
//    cin >> test;
//    while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
