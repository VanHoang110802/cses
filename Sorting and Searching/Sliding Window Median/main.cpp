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
int a[MAXN];
int n, k;
array<int, 2> med = { -1 };
set<array<int, 2> > bot, top;

void fix()
{
	int m = 1 + bot.size() + top.size();
	if (bot.size()<(m - 1)/2)
	{
		bot.insert(med);
		med = *top.begin();
		top.erase(med);
	}
	if (bot.size() > (m - 1) / 2)
	{
		top.insert(med);
		med = *--bot.end();
		bot.erase(med);
	}
}

void add(array<int, 2> x)
{
	if (med[0] == -1)
	{
		med = x;
		return;
	}
	if (x < med)
	{
		bot.insert(x);
	}
	else
	{
		top.insert(x);
	}
	fix();
}

void rem(array<int, 2> x)
{
	if (x == med)
	{
		med = *top.begin();
		top.erase(med);
	}
	else if (x < med)
	{
		bot.erase(x);
	}
	else
	{
		top.erase(x);
	}
	fix();
}

void XuLy()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	if (k == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << ' ';
		}
		return;
	}
	for (int i = 0; i < k - 1; ++i)
	{
		add({ a[i], i });
	}
	for (int i = k - 1; i < n; ++i)
	{
		add({ a[i], i });
		cout << med[0] << ' ';
		rem({ a[i - k + 1], i-k+1 });
	}
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
