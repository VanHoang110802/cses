#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 5;
int N, M, timer, in[MAXN];
bool even[MAXN];
vector<pair<int, int> > G[MAXN];
pair<int, int> ans[MAXN];

void dfs(int u, int p = -1)
{
    in[u] = ++timer;
    for(pair<int, int> e : G[u])
    {
        int v = e.first, id = e.second;
        if(v != p)
        {
            if(!in[v])
            {
                dfs(v, u);
                if(even[v])
                {
                    ans[id] = {u, v};
                    even[u] ^= true;
                }
                else
                {
                    ans[id] = {v, u};
                    even[v] ^= true;
                }
            }
            else if(in[v] < in[u])
            {
                even[u] ^= true;
                ans[id] = {u, v};
            }
        }
    }
}

void XuLy()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    fill(even + 1, even + MAXN + 1, true);
    for(int i = 1; i <= MAXN; i++)
        if(!in[i])
            dfs(i);

    bool good = true;
    for(int i = 1; i <= N; i++)
        good &= even[i];

    if(good)
    {
        for(int i = 0; i < M; i++)
            cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    else cout << "IMPOSSIBLE\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //int test;
    //cin >> test;
    //while(test--)
    XuLy();

    //cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
