#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
vector<pair<int, int> > adj[MAXN];
int vis[MAXN];

void XuLy()
{
    int n, m, k;
    cin >> n >> m >> k;
    //https://en.wikipedia.org/wiki/K_shortest_path_routing
    for(int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    priority_queue<pair<int, int> > q;
    q.push({0, 1});
    while(!q.empty() && vis[n] < k)
    {
        int a = q.top().second;
        int d = q.top().first;
        q.pop();
        vis[a]++;
        if(a == n)
        {
            cout << -d << ' ';
        }
        if(vis[a] <= k)
        {
            for(auto [b, w] : adj[a])
            {
                q.push({d - w, b});
            }
        }
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
