#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+5;
char S[MAXN];
int N, bestl, bestr, d1[MAXN], d2[MAXN];

void XuLy()
{
    cin >> S;
    N = (int)strlen(S);

    for(int i = 0, l = 0, r = -1; i < N; i++)
    {
        int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
        while(0 <= i-k && i+k < N && S[i-k] == S[i+k])
        {
            k++;
        }
        if(2 * k - 1 > bestr - bestl + 1)
        {
            bestl = i - k + 1;
            bestr = i + k - 1;
        }

        d1[i] = k--;
        if(i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }

    for(int i = 0, l = 0, r = -1; i < N; i++)
    {
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
        while(0 <= i - k - 1 && i + k < N && S[i - k - 1] == S[i + k])
        {
            k++;
        }
        if(2 * k > bestr - bestl + 1)
        {
            bestl = i - k;
            bestr = i + k - 1;
        }
        d2[i] = k--;
        if(i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
    for(int i = bestl; i <= bestr; i++)
        cout << S[i];
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
