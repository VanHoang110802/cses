#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <functional>
#include <queue>
#include <stack>
#include <array>
#include <list>
#include <vector>
using namespace std;

//#define int long long
const int MAXN = 2e5 + 7;
vector<int> adj[MAXN], ans;
int p[MAXN];
int n, m;

void XuLy()
{
    cin >> n >> m;
    for(int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(p, -1, 4 * n);
    queue<int> qu;
    qu.push(0);
    p[0] = -2;
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();
        for(auto v : adj[u])
        {
            if(p[v] < 0)
            {
                p[v] = u;
                qu.push(v);
            }
        }
    }
    if(p[n - 1] < 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        int u = n - 1;
        while(u)
        {
            ans.push_back(u);
            u = p[u];
        }
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto i : ans) cout << i + 1 << ' ';
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
