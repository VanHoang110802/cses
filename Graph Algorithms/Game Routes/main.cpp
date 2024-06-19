#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> v;
int path[MAXN];

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

void XuLy()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 1; i < n + 1; ++i)
    {
        if(!vis[i]) dfs(i);
    }

    // for (auto i:v) put(i);
    vector<int> t;
    int i = 0, f = 0;
    while(i < v.size())
    {
        if(f == 0)
        {
            if(v[i] == 1)
            {
                f = 1;
                t.push_back(1);
            }
        }
        else
        {
            t.push_back(v[i]);
        }
        i++;
    }
    path[1] = 1;
    for(auto i : t)
    {
        for(auto j : adj[i])
        {
            (path[i] += path[j]) %= mod;
        }
    }
    cout << path[n];
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
