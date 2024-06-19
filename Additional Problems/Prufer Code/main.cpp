#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5+5;
int N, a[MAXN], deg[MAXN];
priority_queue<int, vector<int>, greater<int> > Q;

void XuLy()
{
    cin >> N;
    fill(deg + 1, deg + N + 1, 1);
    for(int i = 0; i < N - 2; i++)
    {
        cin >> a[i];
        deg[a[i]]++;
    }

    for(int i = 1; i <= N; i++)
        if(deg[i] == 1)
            Q.push(i);

    for(int i = 0; i < N - 2; i++)
    {
        int u = a[i];
        int v = Q.top();
        Q.pop();

        deg[u]--;
        deg[v]--;
        if(deg[u] == 1)
            Q.push(u);

        cout << u << ' ' << v << '\n';
    }

    for(int i = 1; i <= N; i++)
        if(deg[i])
            cout << i << ' ';
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
