#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 5e3 + 7;
const int MAXX = 1e16;
int dis[MAXN];
vector<int> adj[MAXN], adj2[MAXN];
bool vis[MAXN], vis2[MAXN];

void dfs(int s)
{
    if(vis[s])
    {
        return;
    }
    vis[s] = true;
    for(auto i : adj[s])
    {
        dfs(i);
    }
}

void dfs2(int s)
{
    if(vis2[s])
    {
        return;
    }
    vis2[s] = true;
    for(auto i : adj2[s])
    {
        dfs2(i);
    }
}

void XuLy()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n + 1; ++i)
    {
        dis[i] = MAXX;
    }
    dis[1] = 0;
    vector<tuple<int, int, int> > e;
    for(int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        e.push_back({a, b, -w});
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    dfs(1);
    dfs2(n);
    for(int i = 0; i < n; ++i)
    {
        for(auto [a, b, w] : e)
        {
            if (dis[b] > dis[a] + w)
            {
                dis[b] = dis[a] + w;
                if (i == n - 1 && vis[b] && vis2[b])
                {
                    cout << -1;
                    return;
                }
            }
        }
    }
    cout << -dis[n];
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
