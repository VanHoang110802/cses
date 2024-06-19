#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define int long long

void XuLy()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1;
    }
    else if(n <= 3)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        int soChan = 2;
        while(soChan <= n)
        {
            cout << soChan << ' ';
            soChan += 2;
        }
        int soLe = 1;
        while(soLe <= n)
        {
            cout << soLe << ' ';
            soLe += 2;
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
    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
