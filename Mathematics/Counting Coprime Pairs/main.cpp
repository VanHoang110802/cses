#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1 << 60;
const int MAXN = 1e6 + 7;
int cnt[MAXN], isPrime[MAXN];

void sieve()
{
    isPrime[0] = 1;
    for(int i = 1; i < MAXN; i++) isPrime[i] = i;
    for(int i = 2; i * i < MAXN; i++)
    {
        if(isPrime[i] == i)
        {
            for(int j = i * i; j < MAXN; j += i)
            {
                if(isPrime[j] == j) isPrime[j] = i;
            }
        }
    }
}

void XuLy()
{
    int n;
    cin >> n;
    int ans = 0;
    sieve();
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<int> v;
        while(x > 1)
        {
            int y = isPrime[x];
            v.push_back(y);
            while(x % y == 0)
            {
                x /= y;
            }
        }
        int k = v.size();
        for(int s = 1; s < (1 << k); s++)
        {
            int p = 1;
            for(int j = 0; j < k; j++)
            {
                if (s >> j & 1)
                {
                    p *= v[j];
                }
            }
            int sgn = -1;
            if(__builtin_popcount(s)&1) sgn = 1;
            ans += sgn * cnt[p];
            cnt[p]++;
        }
    }
    cout << n * (n - 1) / 2 - ans;
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
