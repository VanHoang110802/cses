#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define int long long

void XuLy()
{
    string s; cin >> s;
    int c[26] = {}, c1 = 0;
    for(char d : s)
    {
        ++c[d - 'A'];
    }
    for(int i = 0; i < 26; ++i)
    {
        c1 += c[i] & 1;
    }
    if(c1 > 1)
    {
        cout << "NO SOLUTION";
        return;
    }
    string t;
    for(int i = 0;i < 26; ++i)
    {
        if(c[i] & 1 ^ 1)
        {
            for(int j = 0; j < c[i] / 2; ++j)
            {
                t += (char)('A' + i);
            }
        }
    }
    cout << t;
    for(int i = 0; i < 26; ++i)
    {
        if(c[i] & 1)
        {
            for(int j = 0; j < c[i]; ++j)
            {
                cout << (char)('A' + i);
            }
        }
    }
    reverse(t.begin(), t.end());
    cout << t;
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
