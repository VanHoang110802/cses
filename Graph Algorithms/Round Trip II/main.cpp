#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int vis[MAXN];
vector<int> cyc;

bool dfs(int s)
{
    vis[s] = 1;
    for(auto i : adj[s])
    {
        cyc.push_back(i);
        if(vis[i] == 0)
        {
            if(dfs(i))
            {
                return true;
            }
        }
        else if(vis[i] == 1)
        {
            return true;
        }
        cyc.pop_back();
    }
    vis[s] = 2;
    return false;
}

void XuLy()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i < n + 1; ++i)
    {
        cyc.push_back(i);
        if(!vis[i] && dfs(i))
        {
            vector<int> ans = {*cyc.rbegin()};
            for (auto j = cyc.rbegin() + 1; j != cyc.rend(); j++)
            {
                ans.push_back(*j);
                if(*j == *cyc.rbegin())
                {
                    break;
                }
            }
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            for(auto i : ans) cout << i << ' ';
            return;
        }
        cyc.pop_back();
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
