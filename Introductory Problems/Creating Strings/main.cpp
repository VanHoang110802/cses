#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define int long long

void XuLy()
{
    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    do
    {
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    cout << ans.size() << '\n';
    for(string a : ans) cout << a << '\n';
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
