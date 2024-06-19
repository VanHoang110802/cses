#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int a[MAXN];
int n, t;

void XuLy()
{
    cin >> n >> t;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int lb = 1, rb = 1e18;
    while(lb < rb)
    {
        int mb = (lb + rb) / 2, s = 0;
        for(int i = 0; i < n; ++i)
        {
            s += (min(mb / a[i], (int)1e9));
        }
        if(s >= t)
        {
            rb = mb;
        }
        else
        {
            lb = mb + 1;
        }
    }
    cout << lb;
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
