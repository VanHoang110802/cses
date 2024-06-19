#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <unordered_map>
using namespace std;

#define int long long
const int MAXN = 5e3 + 7;
int a[MAXN];
int n, k;

void XuLy()
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    unordered_map<int, array<int, 2> > UMAP;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(UMAP.find(k - a[i] - a[j]) != UMAP.end())
            {
                array<int, 2> ans = UMAP[k - a[i]- a[j]];
                cout << i + 1 << ' ' << j + 1 << ' ' << ans[0] + 1 << ' ' << ans[1] + 1;
                return;
            }
        }
        for(int j = 0; j < i; ++j)
        {
            UMAP[a[i] + a[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE";
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
