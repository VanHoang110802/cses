#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int dp[MAXN], ans[MAXN][19];
int n, q;

void dfs(int u = 0, int p = -1)
{
    ans[u][0] = p;
    for(int i = 1; i < 19; ++i)
    {
        ans[u][i] = ~ans[u][i - 1] ? ans[ans[u][i - 1]][i - 1] : -1;
    }
    for(auto v : adj[u])
    {
        if(v == p)
        {
            continue;
        }
        dp[v] = dp[u] + 1;
        dfs(v, u);
    }
}

void XuLy()
{
    cin >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        --x;
        adj[x].push_back(i);
    }
    dfs();
    while(q--)
    {
        int x, y; cin >> x >> y;
        --x;
        if(dp[x] < y)
        {
            cout << -1 << '\n';
        }
        else
        {
            for(int i = 18; ~i; --i)
            {
                if(y >> i & 1)
                {
                    x = ans[x][i];
                }
            }
            cout << x + 1 << '\n';
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

//    int test;
//    cin >> test;
//    while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
