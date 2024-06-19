#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>
#include <string>
using namespace std;

#define int long long
const int MAXS = 8;
string s[MAXS];
bool b[MAXS + 7];
void XuLy()
{
    for(int i = 0; i < MAXS; ++i) cin >> s[i];
    int p[MAXS], ans = 0;
    iota(p, p + 8, 0);
    do
    {
        bool ok = true;
        for(int i = 0; i < MAXS; ++i)
        {
            ok &= s[i][p[i]] == '.';
        }
        memset(b, false, MAXS + 7);
        for(int i = 0; i < MAXS; ++i)
        {
            if(b[i + p[i]])
            {
                ok = false;
            }
            b[i + p[i]] = true;
        }
        memset(b, false, MAXS + 7);
        for(int i = 0; i < MAXS; ++i)
        {
            if(b[i + 7 - p[i]])
            {
                ok = false;
            }
            b[i + 7 - p[i]] = true;
        }
        ans += (int)ok;
    } while(next_permutation(p, p + MAXS));
    cout << ans << '\n';
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
