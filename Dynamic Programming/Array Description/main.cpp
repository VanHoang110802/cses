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
const int MAXN = 1e5 + 7;
const int MAXM = 1e2 + 7;
const int mod = 1e9 + 7;
int dp[MAXN][MAXM], a[MAXN];

void XuLy()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		--a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (i)
		{
			for (int j = 0; j < m; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (j)
				{
					dp[i][j] += dp[i - 1][j - 1];
				}
				if (j < m - 1)
				{
					dp[i][j] += dp[i - 1][j + 1];
				}
				dp[i][j] %= mod;
			}
		}
		else
		{
			for (int j = 0; j < m; ++j)
			{
				dp[0][j] = 1;
			}
		}
		if (~a[i])
		{
			for (int j = 0; j < m; ++j)
			{
				if (j ^ a[i])
				{
					dp[i][j] = 0;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < m; ++i)
	{
		ans += dp[n - 1][i];
	}
	cout << ans % mod;
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
