#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
int n, x;
vector <int> arr;

void XuLy()
{
    cin >> n >> x;
    arr.resize(n);
    for(int i = 0;i<n;++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int l = 0, r = n-1;
    int ans = 0;
    while(l <= r)
    {
        ans++;
        if(arr[l] + arr[r] <= x)
        {
            l++;
        }
        r--;
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

    //int test;
    //cin >> test;
    //while(test--)
        XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
