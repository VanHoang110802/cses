#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 5;
struct Node
{
    int len, link;
    map<char, int> nxt;
} node[MAXN];
char S[MAXN];
bool vis[MAXN];
int N, sz, last, dist[MAXN];
int ans[MAXN];

void extend(char c)
{
    int cur = sz++;
    node[cur].len = node[last].len + 1;
    int p = last;
    while(p != -1 && !node[p].nxt.count(c))
    {
        node[p].nxt[c] = cur;
        p = node[p].link;
    }
    if(p == -1)
    {
        node[cur].link = 0;
    }
    else
    {
        int q = node[p].nxt[c];
        if(node[p].len + 1 == node[q].len)
        {
            node[cur].link = q;
        }
        else
        {
            int clone = sz++;
            node[clone].len = node[p].len + 1;
            node[clone].nxt = node[q].nxt;
            node[clone].link = node[q].link;
            while(p != -1 && node[p].nxt[c] == q)
            {
                node[p].nxt[c] = clone;
                p = node[p].link;
            }
            node[q].link = node[cur].link = clone;
        }
    }
    last = cur;
}

void init()
{
    node[0].len = 0;
    node[0].link = -1;
    sz = 1;
    last = 0;
}

void bfs(int s = 0)
{
    queue<int> Q;
    vis[s] = true;
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        ans[dist[u]]++;
        ans[node[u].len+1]--;
        for(const auto& [c, v] : node[u].nxt)
        {
            if(!vis[v])
            {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                Q.push(v);
            }
        }
    }
}

void XuLy()
{
    cin >> S;
    N = (int)strlen(S);
    init();
    for(int i = 0; i < N; i++)
    {
        extend(S[i]);
    }
    bfs();
    for(int i = 1; i <= N; i++)
    {
        ans[i] += ans[i-1];
        cout << ans[i] << (" \n")[i == N];
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
