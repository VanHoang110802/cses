#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 5e3 + 7;
int dis[MAXN], par[MAXN];

void XuLy()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int> > e;
    for(int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        e.push_back({a, b, w});
    }
    //bellman-ford

    for(int i = 1; i < n + 1; ++i)
    {
        dis[i] = 1e18;
    }
    dis[1] = 0;
    int f;
    for(int i = 1; i < n + 1; ++i)
    {
        f = 0;
        for(auto [a, b, w] : e)
        {
            if(dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
                par[b] = a;
                f = b;
            }
        }
    }
    if(!f)
    {
        cout << "NO";
        return;
    }
    else
    {
        cout << "YES\n";
        vector<int> cyc;
        for(int i = 1; i < n + 1; ++i)
        {
            f = par[f];
        }
        for(int x = f;; x = par[x])
        {
            cyc.push_back(x);
            if(x == f && cyc.size() > 1)
            {
                break;
            }
        }
        reverse(cyc.begin(), cyc.end());
        for(auto i : cyc) cout << i << ' ';
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
