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

const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
int dp[MAXN], a[MAXN];

void XuLy()
{
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1e9;
		int temp = i;
		while (temp)
		{
			dp[i] = min(dp[i], dp[i - temp % 10] + 1);
			temp /= 10;
		}
	}
	cout << dp[n];
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
