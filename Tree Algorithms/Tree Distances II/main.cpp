#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int dp[MAXN], ans[MAXN], s[MAXN];
int n;

void dfs(int u = 0, int p = -1)
{
    s[u] = 1;
    for(auto v : adj[u])
    {
        if(v == p)
        {
            continue;
        }
        dp[v] = dp[u] + 1;
        dfs(v, u);
        s[u] += s[v];
    }
}

void dfs2(int u, int pd, int p = -1)
{
    ans[u] = pd;
    for(auto v : adj[u])
    {
        if(v == p)
        {
            continue;
        }
        dfs2(v, pd - s[v] + (n - s[v]), u);
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
    int sd = 0;
    for(int i = 0; i < n; ++i)
    {
        sd += dp[i];
    }
    dfs2(0, sd);
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
