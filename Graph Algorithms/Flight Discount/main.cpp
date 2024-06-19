#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int vis[MAXN];
int dis1[MAXN], dis2[MAXN];
vector<pair<int, int> > adj1[MAXN], adj2[MAXN];
vector<tuple<int, int, int> > e;

void dij(int s, int dis[], vector<pair<int, int> > adj[])
{
    priority_queue<pair<int, int> > q;
    for(int i = 1; i < MAXN; ++i)
    {
        dis[i] = 1e18;
    }
    dis[s] = 0;
    q.push({0, s});
    memset(vis, 0, sizeof(vis));
    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if(vis[a])
        {
            continue;
        }
        vis[a] = 1;
        for(auto [b, w] : adj[a])
        {
            if(dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
}

void XuLy()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int a,b,w;
        cin >> a >> b >> w;
        e.push_back({a, b, w});
        adj1[a].push_back({b, w});
        adj2[b].push_back({a, w});
    }
    dij(1, dis1, adj1);
    dij(n, dis2, adj2);
    int mn = 1e18;
    for(auto [a,b,w] : e)
    {
        mn = min(mn, dis1[a] + dis2[b] + w / 2);
    }
    cout << mn;
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
