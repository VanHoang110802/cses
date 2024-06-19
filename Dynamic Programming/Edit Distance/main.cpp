#pragma warning(disable:4996)
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
using namespace std;

#define int long long
const int MAXN = 5e3 + 7;
const int mod = 1e9 + 7;
int dp[MAXN][MAXN];

void XuLy()
{
	string s, t;
	cin >> s >> t;
	for (int i = 1; i <= s.size(); ++i)
	{
		dp[i][0] = i;
	}
	for (int i = 1; i <= t.size(); ++i)
	{
		dp[0][i] = i;
	}
	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = 1; j <= t.size(); ++j)
		{
			dp[i][j] = 1e9;
			if (s[i - 1] == t[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			dp[i][j] = min({ dp[i][j] - 1, dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
		}
	}
	cout << dp[s.size()][t.size()];
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
