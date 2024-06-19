#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int a[MAXN];
map<int,int> cnt;

void XuLy()
{
    int k, n;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 0, c = 0, ans = 0;
    while(l < n)
    {
        while(r < n && c + (cnt[a[r]] == 0) <= k)
        {
            cnt[a[r]]++;
            c += (cnt[a[r]] == 1);
            r++;
        }
        ans += r - l;
        c -= (cnt[a[l]] == 1);
        cnt[a[l]]--, l++;
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
