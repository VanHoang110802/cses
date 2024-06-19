#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 9;
const int mod = 1e9 + 7;
const int inf = 1LL << 62;
const int x[] = {0, 1, 2, 3, 4, 5, 1, 2, 4, 5, 7, 8};
const int y[] = {3, 4, 5, 6, 7, 8, 0, 1, 3, 4, 6, 7};
unordered_map<string, int> dist;
queue<string> Q;
string perm;

void init()
{
    perm = "123456789";
    dist[perm] = 1;
    Q.push(perm);
    while(!Q.empty())
    {
        perm = Q.front();
        Q.pop();
        int d = dist[perm];
        for(int i = 0; i < 12; i++)
        {
            swap(perm[x[i]], perm[y[i]]);
            if(!dist[perm])
            {
                dist[perm] = d + 1;
                Q.push(perm);
            }
            swap(perm[x[i]], perm[y[i]]);
        }
    }
}

void XuLy()
{
    init();
    for(int i = 0; i < MAXN; i++)
        cin >> perm[i];
    cout << dist[perm] - 1;
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
