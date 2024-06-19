#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 5;
int N, p[MAXN], sz[MAXN];
vector<int> G[MAXN];

void dfs(int u = 1)
{
    sz[u] = 1;
    for(int v : G[u])
    {
        if(v != p[u])
        {
            p[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
    }
}

void XuLy()
{
    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();

    for(int i = 1; i <= N; i++)
    {
        bool centroid = true;

        if(p[i] != 0 && N - sz[i] > N/2)
            centroid = false;

        for(int v : G[i])
            if(v != p[i] && sz[v] > N/2)
                centroid = false;

        if(centroid)
        {
            cout << i;
            return;
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
