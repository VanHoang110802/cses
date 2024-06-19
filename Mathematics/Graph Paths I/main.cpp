#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;

vector<vector<int> > mul(vector<vector<int> > a, vector<vector<int> > b)
{
    vector<vector<int> > c(a.size(), vector<int>(b[0].size()));
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b[0].size(); j++)
        {
            for(int k = 0; k < a[0].size(); k++)
            {
                (c[i][j] += a[i][k] * b[k][j] % mod) %= mod;
            }
        }
    }
    return c;
}

vector<vector<int> > exp(vector<vector<int> > x, int y)
{
    vector<vector<int> > r(x.size(), vector<int>(x.size()));
    for(int i = 0; i < x.size(); i++)
    {
        r[i][i] = 1;
    }
    while(y > 0)
    {
        if(y & 1)
        {
            r = mul(r, x);
        }
        y = y >> 1;
        x = mul(x, x);
    }
    return r;
}

void XuLy()
{
    //considering multiple edges
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > adj(n, vector<int>(n));
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x][y]++;
    }
    adj = exp(adj, k);
    cout << adj[0][n - 1];
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
