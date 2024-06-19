#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+5;
int N, F[MAXN];
char S[MAXN];

void XuLy()
{
    cin >> S;

    N = (int)strlen(S);
    for(int i = 0; i < N; i++)
    {
        S[i + N] = S[i];
    }

    N = (int) strlen(S);
    fill(F, F + N, -1);

    int k = 0;
    for(int i = 1; i < N; i++)
    {
        char c = S[i];
        int f = F[i - k - 1];
        while(f != -1 && c != S[k + f + 1])
        {
            if(c < S[k + f + 1])
            {
                k = i - f - 1;
            }
            f = F[f];
        }
        if(c != S[k + f + 1])
        {
            if(c < S[k])
            {
                k = i;
            }
            F[i - k] = -1;
        }
        else F[i-k] = f+1;
    }

    for(int i = 0; i < N/2; i++)
    {
        cout <<  S[i + k];
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
