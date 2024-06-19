#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 5e2 + 7;
int dis[MAXN][MAXN];

void XuLy()
{
    int n, m, q;
    cin >> n >> m >> q;
    int M = 1e18;
    for(int i = 1; i < n + 1; ++i)
    {
        for(int j = 1; j < n + 1; ++j)
        {
            dis[i][j] = M;
        }
    }
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][u] = 0, dis[v][v] = 0;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[u][v], w);
    }
    for(int k = 1; k < n + 1; ++k)
    {
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(dis[a][b] < M) cout << dis[a][b] << '\n';
        else cout << -1 << '\n';
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
