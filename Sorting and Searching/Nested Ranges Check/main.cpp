#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;
int m[MAXN], n[MAXN];

struct ranges
{
    int l, r, in;
    bool operator < (const ranges& other) const
    {
        if(l == other.l)
        {
            return r > other.r;
        }
        return l < other.l;
    }
};

vector<vector<int> > checkrange(vector<vector<int> >& r, int n)
{
    vector<ranges> range(n);
    vector<int> contains(n), contained(n);

    for(int i = 0; i < n; i++)
    {
        range[i].l = r[i][0];
        range[i].r = r[i][1];
        range[i].in = i;
    }

    sort(range.begin(), range.end());

    int minEnd = 2e9;
    for(int i = n - 1; i >= 0; i--)
    {
        if(range[i].r >= minEnd)
        {
            contains[range[i].in] = 1;
        }

        minEnd = min(minEnd, range[i].r);
    }
    int maxEnd = 0;
    for(int i = 0; i < n; i++)
    {
        if(range[i].r <= maxEnd)
        {
            contained[range[i].in] = 1;
        }
        maxEnd = max(maxEnd, range[i].r);
    }

    return {contains, contained};
}

void XuLy()
{
    int n;
    cin >> n;
    vector<vector<int> > r(n, vector<int>(2));
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        r[i][0] = x;
        r[i][1] = y;
    }
    vector<vector<int> > res = checkrange(r, n);
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

//    int test;
//    cin >> test;
//    while(test--)
    XuLy();

    //cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
