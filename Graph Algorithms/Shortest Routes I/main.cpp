#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int vis[MAXN], dis[MAXN];
vector<pair<int, int> > adj[MAXN];

void XuLy()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    //dijkstra
    for(int i = 2; i < n + 1; ++i)
    {
        dis[i] = 1e18;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > q;
    q.push({0, 1});
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for(auto [v, w] : adj[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for(int i = 1; i < n + 1; ++i)
    {
        cout << dis[i] << ' ';
    }
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
