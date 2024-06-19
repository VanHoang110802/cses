#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
char S[MAXN];
int N, M, K;
int tot, bad, fact[MAXN], inv[MAXN];

int inverse(int x)
{
    int res = 1;
    int b = mod - 2;
    while(b)
    {
        if(b&1) res = (res * x) % mod;
        x = (x * x) % mod;
        b >>= 1;
    }
    return res;
}

int choose(int x, int y)
{
    return (fact[x] * inv[y] % mod) * inv[x - y] % mod;
}

void init()
{
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i-1] * i) % mod;
        inv[i] = (inv[i-1] * inverse(i)) % mod;
    }
}

void XuLy()
{
    cin >> N >> S;
    M = (int)strlen(S);
    init();

    int open = 0, closed = 0;
    for(int i = 0; i < M; i++)
    {
        if(S[i] == '(')
        {
            open++;
        }
        else if(S[i] == ')')
        {
            closed++;
        }

        if(closed > open)
        {
            cout << "0\n";
            return;
        }
    }

    if(N & 1 || open > N/2)
    {
        cout << "0\n";
        return;
    }

    tot = choose(N - open - closed, N / 2 - open);
    bad = choose(N - open - closed, N / 2 - open - 1);
    cout << ((tot - bad) % mod + mod) % mod;
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
