#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
const int inf = 1LL << 62;
int N, K;
double ans, a, b;

void XuLy()
{
    cin >> N >> K;
    for(int i = 1; i <= K; i++)
    {
        a = b = 1.0;
        for(int j = 1; j <= N; j++)
        {
            a *= (double)i / K;
            b *= (double)(i - 1) / K;
        }
        ans += (a - b) * i;
    }
    cout << fixed << setprecision(6) << ans;
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
