#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int a[MAXN];
int n;

void XuLy()
{
    cin >> n;
    int cnt = 0;
    for(int i=0; i<n; ++i) cin >> a[i];
 
    for(int i=1; i<n; ++i)
    {
        if(a[i] < a[i-1])
        {
            cnt += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }
    cout << cnt;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    XuLy();
    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
