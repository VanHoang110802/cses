#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>
#include <string>
using namespace std;
 
#define int long long
const int MAXN = 7;
bool visit[MAXN][MAXN];
int ans = 0;
string s;
 
bool CheckTam(int i, int j)
{
    return (i >= 0 && i < 7 && j >= 0 && j < 7 && visit[i][j] == false);
}
 
void dfs(int i, int j, int a = 0)
{
    if(i == 6 && j == 0)
    {
        if(a == 48)
        {
            ++ans;
        }
        return;
    }
    visit[i][j] = true;
    if(s[a] == '?' || s[a] == 'L')
    {
        if(j && visit[i][j - 1] == false)
        {
            if(!(!CheckTam(i, j - 2) && CheckTam(i + 1, j - 1) && CheckTam(i - 1, j - 1)))
            dfs(i, j - 1, a + 1);
        }
    }
    if(s[a] == '?' || s[a] == 'R')
    {
        if(j < 6 && visit[i][j + 1] == false)
        {
            if(!(!CheckTam(i, j + 2) && CheckTam(i + 1, j + 1) && CheckTam(i - 1, j + 1)))
            dfs(i, j + 1, a + 1);
        }
    }
    if(s[a] == '?' || s[a] == 'U')
    {
        if(i && visit[i - 1][j] == false)
        {
            if(!(!CheckTam(i - 2, j) && CheckTam(i - 1, j + 1) && CheckTam(i - 1, j - 1)))
            dfs(i - 1, j, a + 1);
        }
    }
    if(s[a] == '?' || s[a] == 'D')
    {
        if(i < 6 && visit[i + 1][j] == false)
        {
            if(!(!CheckTam(i + 2, j) && CheckTam(i + 1, j + 1) && CheckTam(i + 1, j - 1)))
            dfs(i + 1, j, a + 1);
        }
    }
    visit[i][j] = false;
}
 
void XuLy()
{
    cin >> s;
    dfs(0, 0);
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
