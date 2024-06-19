#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> v;
int v1[MAXN];

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
    v.push_back(s);
}

bool cycle(int s)
{
    v1[s] = 1;
    for(auto i : adj[s])
    {
        if(!v1[i])
        {
            if(cycle(i))
            {
                return true;
            }
        }
        else if (v1[i] == 1)
        {
            return true;
        }
    }
    v1[s] = 2;
    return 0;
}

void XuLy()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 1; i < n + 1; ++i)
    {
        if(!v1[i] && cycle(i))
        {
            cout << "IMPOSSIBLE";
            return;
        }
        if(!vis[i])
        {
            dfs(i);
        }
    }
    for(auto i : v) cout << i << ' ';
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
