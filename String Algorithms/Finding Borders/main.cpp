#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
        {
            j = pi[j-1];
        }
        if(s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

void XuLy()
{
    string s;
    cin >> s;
    vector<int> v = prefix(s), ans;
    int j = v[s.size() - 1];
    while(j > 0)
    {
        ans.push_back(j);
        j = v[j - 1];
    }
    sort(ans.begin(), ans.end());
    for(auto i : ans) cout << i << ' ';
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
