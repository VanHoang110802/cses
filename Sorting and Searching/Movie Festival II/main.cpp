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
array<int, 3> a[MAXN];
int temp[MAXN];

void XuLy()
{
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i][1] >> a[i][0];
		a[i][2] = i;
	}
	sort(a, a + n);
	set<array<int, 2> > SET;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		auto it = SET.lower_bound({ a[i][1] + 1});
		if (it != SET.begin())
		{
			--it;
			temp[a[i][2]] = (*it)[1];
			SET.erase(it);
		}
		else temp[a[i][2]] = SET.size();
		if (SET.size() < k)
		{
			SET.insert({ a[i][0], temp[a[i][2]] });
			++ans;
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
