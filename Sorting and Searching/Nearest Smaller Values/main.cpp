#include <iostream>
#include <iomanip>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
int a[MAXN], b[MAXN];
int n;

void XuLy()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = i - 1;
        while(~b[i] && a[b[i]] >= a[i])
        {
            b[i] = b[b[i]];
        }
        cout << b[i] + 1 << ' ';
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
