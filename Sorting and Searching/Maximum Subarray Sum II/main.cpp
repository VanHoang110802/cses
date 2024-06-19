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

#define int long long
const int MAXN = 2e5 + 7;
int c[MAXN];

void XuLy()
{
	int n, a, b; cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i + 1];
		c[i + 1] += c[i];
	}
	set<array<int, 2> >SET;
	int ans = -1e18;
	for (int i = 0; i <= n; ++i)
	{
		if (i >= a)
		{
			SET.insert({ c[i - a], i - a });
		}
		if (SET.size())
		{
			ans = max(c[i] - (*SET.begin())[0], ans);
		}
		if (i >= b)
		{
			SET.erase({ c[i - b], i - b });
		}
	}
	cout << ans;
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
