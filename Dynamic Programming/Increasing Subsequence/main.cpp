#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

#define int long long
int n;

void XuLy()
{
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        int temp = lower_bound(v.begin(), v.end(), x) - v.begin();
        if(temp < v.size())
        {
            v[temp] = x;
        }
        else
        {
            v.push_back(x);
        }
    }
    cout << v.size();
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
