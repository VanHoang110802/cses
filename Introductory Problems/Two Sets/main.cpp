#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

void XuLy()
{
    int n; cin >> n;
    if(n * (n + 1) / 2 % 2)
    {
        cout << "NO";
        return;
    }
    vector<int> v1, v2;
    int j = 0;
    if(n % 4) j = 3;
    else j = 4;
    for(int i = 0; i < (n - 1) / 4; ++i)
    {
        v1.push_back(4 * i + 1 + j);
        v1.push_back(4 * i + 4 + j);
        v2.push_back(4 * i + 2 + j);
        v2.push_back(4 * i + 3 + j);
    }
    if(n % 4)
    {
        v1.push_back(1);
        v1.push_back(2);
        v2.push_back(3);
    }
    else
    {
        v1.push_back(1);
        v1.push_back(4);
        v2.push_back(3);
        v2.push_back(2);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << "YES\n" << v1.size() << '\n';
    for(auto i : v1) cout << i << ' ';
    cout << '\n' << v2.size() << '\n';
    for(auto i : v2) cout << i << ' ';
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
