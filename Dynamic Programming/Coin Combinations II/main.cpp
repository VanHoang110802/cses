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
using namespace std;

const int MAXN = 1e2 + 7;
const int MAXX = 1e6 + 7;
const int mod = 1e9 + 7;
int dp[MAXX], a[MAXN];

void XuLy()
{
	int n, x; cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	dp[0] = 1;
	for (int j = 0; j < n; ++j)
	{
		for (int i = 1; i <= x; ++i)
		{
			if (a[j] <= i)
			{
				dp[i] = (dp[i] + dp[i - a[j]]) % mod;
			}
		}
	}
	cout << dp[x];
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
