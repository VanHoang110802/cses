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

const int MAXN = 1e3 + 7;
const int mod = 1e9 + 7;
int dp[MAXN][MAXN];
string s[MAXN];

void XuLy()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> s[i];
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i)
			{
				dp[i][j] += dp[i - 1][j];
			}
			if (j)
			{
				dp[i][j] += dp[i][j - 1];
			}
			dp[i][j] %= mod;
			if (s[i][j] == '*')
			{
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[n - 1][n - 1];
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
