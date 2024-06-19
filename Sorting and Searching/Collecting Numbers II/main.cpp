#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;
int m[MAXN], n[MAXN];

void XuLy()
{
    int A, B;
    cin >> A >> B;
    for(int i = 0; i < A; ++i)
    {
        int k;
        cin >> k;
        m[i + 1] = k;
        n[k] = i + 1;
    }
    int ans = 1;
    for(int i = 1; i < A; ++i)
    {
        if(n[i] > n[i + 1])
        {
            ans++;
        }
    }
    for(int i = 0; i < B; ++i)
    {
        int x, y;
        cin >> x >> y;
        int a = m[x], b = m[y];

        if(a > 1 && n[a] < n[a - 1])
        {
            ans--;
        }
        if(a < A && n[a + 1] < n[a])
        {
            ans--;
        }
        if(b > 1)
        {
            if(b - 1 != a)
            {
                if(n[b] < n[b - 1])
                {
                    ans--;
                }
            }
        }
        if(b < A)
        {
            if(b + 1 != a)
            {
                if(n[b + 1] < n[b])
                {
                    ans--;
                }
            }
        }
        swap(m[x], m[y]);
        swap(n[a], n[b]);
        if(a > 1)
        {
            if(n[a] < n[a - 1])
            {
                ans++;
            }
        }
        if(a < A)
        {
            if(n[a + 1] < n[a])
            {
                ans++;
            }
        }
        if(b > 1)
        {
            if(b - 1 != a)
            {
                if(n[b] < n[b - 1])
                {
                    ans++;
                }
            }
        }
        if(b < A)
        {
            if(b + 1 != a)
            {
                if(n[b + 1] < n[b])
                {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

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
