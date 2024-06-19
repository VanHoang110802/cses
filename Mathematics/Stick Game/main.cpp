#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
const int inf = 1LL << 62;
int dp[MAXN];

void XuLy()
{
    int n, k;
    cin >> n >> k;

    dp[0] = 0;
    vector<int> p;
    for(int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        p.push_back(x);
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for(auto j : p)
        {
            if(i - j >= 0)
            {
                if(dp[i - j] == 0)
                {
                    dp[i] = 1;
                }
            }
        }
        if(dp[i]) cout << 'W';
        else cout << 'L';
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
