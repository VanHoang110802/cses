#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 5;
vector<pair<int, int> > ans;
int flag = 0, cnt = 0;
vector<int> adj[MAXN];
int vis[MAXN], low[MAXN];

void dfs(int s, int p)
{
    vis[s] = ++cnt;
    low[s] = vis[s];
    for(auto i : adj[s])
    {
        if(i != p)
        {
            if(vis[i])
            {
                low[s] = min(low[s], vis[i]);
                if(vis[i] > vis[s])
                    ans.push_back({i, s});
            }
            else
            {
                dfs(i, s);
                ans.push_back({s, i});
                low[s] = min(low[i], low[s]);
                if(low[i] > vis[s])
                    flag = 1;
            }
        }
    }
}

void XuLy()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    if(flag == 1)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    for(auto [i, j] : ans)
        cout << i << ' ' << j << '\n';
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
