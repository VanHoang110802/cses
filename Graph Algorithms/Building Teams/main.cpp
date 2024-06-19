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
int c[MAXN];
bool visited[MAXN];
int n, m;

void dfs(int u, int temp = 0)
{
    if(~c[u])
    {
        if(c[u] ^ temp)
        {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        return;
    }
    c[u] = temp;
    for(auto v : adj[u])
    {
        dfs(v, temp^1);
    }
}

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
    memset(c, -1, 4 * n);
    for(int i = 0; i < n; ++i)
    {
        if(c[i] < 0)
        {
            dfs(i);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        cout << c[i] + 1 << ' ';
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
