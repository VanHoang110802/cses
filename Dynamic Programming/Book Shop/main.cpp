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
const int MAXX = 1e5 + 7;
const int mod = 1e9 + 7;
int dp[MAXX], a[MAXN], b[MAXN];

void XuLy()
{
	int n, x; cin >> n >> x;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = x; j >= a[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
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
