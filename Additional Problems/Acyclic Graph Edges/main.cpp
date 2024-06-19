#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5+5;
int N, M, a, b;

void XuLy()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << min(a, b) << ' ' << max(a, b) << '\n';
    }
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
