#include <iostream>
#include <iomanip>
using namespace std;

#define int long long
int n;

void XuLy()
{
    cin >> n;
    if(n == 1) cout << 1;
    else
    {
        cout << n << ' ';
        while(true)
        {
            if(n == 1) break;
            if(n % 2 == 0) n /= 2;
            else n = (n * 3) + 1;
            cout << n << ' ';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    XuLy();
    cout << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    return 0;
}
