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

//#define int long long
const int MAXX = 1e5 + 7;
const int MAXN = 1e2 + 7;
const int mod = 1e9 + 7;
int dp[MAXX], a[MAXN];

void XuLy()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	dp[0] = 1;
	for (int j = 0; j < n; ++j)
	{
		for (int i = MAXX; i; --i)
		{
			if (i >= a[j])
			{
				dp[i] |= dp[i - a[j]];
			}
		}
	}
	vector<int> ans;
	for (int i = 1; i <= MAXX; ++i)
	{
		if (dp[i])
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
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
