#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1 << 62;
const int MAXK = 1e6 + 7;
const int MAXN = 5e3 + 7;
const int mod = 1e9 + 7;
int trie[MAXK][26];
bool stop[MAXK];
int dp[MAXN];
int ct = 0;
string s;

void insert(string s)
{
    int node = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(!trie[node][s[i] - 'a'])
        {
            trie[node][s[i] - 'a'] = ++ct;
        }
        node = trie[node][s[i] - 'a'];
    }
    stop[node] = 1;
}

int search(int x)
{
    int node = 0, ans = 0;
    for(int i = x; i < s.size(); i++)
    {
        if(!trie[node][s[i]-'a'])
        {
            return ans;
        }
        node = trie[node][s[i] - 'a'];
        if (stop[node])
        {
            (ans += dp[i + 1]) %= mod;
        }
    }
    return ans;
}

void XuLy()
{
    cin >> s;
    int k;
    cin >> k;
    while(k--)
    {
        string x;
        cin >> x;
        insert(x);
    }
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        dp[i] = search(i);
    }
    cout << dp[0];
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
