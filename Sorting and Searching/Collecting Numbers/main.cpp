#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e6 + 7;
const int mod = 1e9 + 7;
int a[MAXN];
int n;

void XuLy()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 1;
    vector<int> indices(n + 1);
    for(int i = 0; i < n; ++i)
    {
        indices[a[i]] = i;
    }
    for(int i = 1; i < n; ++i)
    {
        if(indices[i + 1] < indices[i])
        {
            ans++;
        }
    }
    cout << ans;
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
