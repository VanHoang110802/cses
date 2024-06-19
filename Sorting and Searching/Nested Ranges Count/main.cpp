#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;
map<int, int> mp;
int T[MAXN] = {0};

void update(int n, int x, int val)
{
    for(; x <= n; x += x & -x)
    {
        T[x] += val;
    }
}
int query(int x)
{
    int s = 0;
    for(; x > 0; x -= x & -x)
    {
        s += T[x];
    }
    return s;
}

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if(a.F.F == b.F.F)
    {
        return a.F.S > b.F.S;
    }
    return a.F.F < b.F.F;
}

void XuLy()
{
    int n;
    cin >> n;
    set<int> b;
    vector<pair<pair<int, int>, int> > v(n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i].S = i;
        v[i].F = {x, y};
        b.insert(y);
    }
    int cnt = 0;
    for(auto i : b)
    {
        mp[i] = ++cnt;
    }
    sort(v.begin(), v.end(), comp);
    update(cnt, mp[v[n - 1].F.S], 1);
    int ans[n] = {0};
    for(int i = n - 2; i >= 0; i--)
    {
        ans[v[i].S] += query(mp[v[i].F.S]);
        update(cnt, mp[v[i].F.S], 1);
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }

    memset(ans, 0, sizeof(ans));
    memset(T, 0, sizeof(T));
    update(cnt, 1, 1);
    update(cnt, mp[v[0].F.S] + 1, -1);
    for(int i = 1; i < n; i++)
    {
        ans[v[i].S] += query(mp[v[i].F.S]);
        update(cnt, 1, 1);
        update(cnt, mp[v[i].F.S] + 1, -1);
    }
    cout << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
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
