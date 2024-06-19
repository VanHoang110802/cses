#include <bits/stdc++.h>
using namespace std;

void z(string s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
    {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            x = i;
            y = i + z[i];
            z[i]++;
        }
        if(z[i] + i == n) cout << i << ' ';
    }
    cout << n;
}

void XuLy()
{
    string s;
    cin >> s;
    z(s);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

//    int test;
//    cin >> test;
//    while(test--)
    XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
