#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void XuLy()
{
    string s;
    cin >> s;
    int MAX = 0, dem = 0;
    for(int i=0; i<s.size(); ++i)
    {
        ++dem;
        MAX = max(MAX, dem);
        if(s[i] != s[i+1]) dem = 0;
    }
    cout << MAX;

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
