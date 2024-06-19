#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int dp[MAXN], ans[MAXN];
int n;

void dfs(int u = 0, int p = -1)
{
    for(auto v : adj[u])
    {
        if(v == p)
        {
            continue;
        }
        dfs(v, u);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

void dfs2(int u = 0, int p = -1, int pd = 0)
{
    ans[u] = max(dp[u], pd);
    vector<array<int, 2> > w{{pd, -1}};
    for(auto v : adj[u])
    {
        if(v == p)
        {
            continue;
        }
        w.push_back({dp[v] + 1, v});
    }
    w.push_back({0, - 1});
    sort(w.begin(), w.end(), greater<array<int, 2> >());
    for(auto v : adj[u])
    {
        if(v == p)
        {
            continue;
        }
        if(w[0][1] == v)
        {
            dfs2(v, u, w[1][0] + 1);
        }
        else
        {
            dfs2(v, u, w[0][0] + 1);
        }
    }
}

void XuLy()
{
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    dfs2();
    for(int i = 0; i < n; ++i)
    {
        cout << ans[i] << ' ';
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
