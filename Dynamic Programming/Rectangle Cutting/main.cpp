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
const int MAXN = 5e2 + 7;
const int mod = 1e9 + 7;
int dp[MAXN][MAXN];

void XuLy()
{
	int a, b; cin >> a >> b;
	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			if (i ^ j)
			{
				dp[i][j] = 1e9;
			}
			for (int k = 1; k < i; ++k)
			{
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
			}
			for (int k = 1; k < j; ++k)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
			}
		}
	}
	cout << dp[a][b];
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
