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
const int MAXN = 1e3 + 7;
int n, m, ans = 0;
string s[MAXN];

bool check(int i, int j)
{
	return (i >= 0 && i < n && j >= 0 && s[i][j] == '.');
}

void dfs(int i, int j)
{
	s[i][j] = '#';
	if (check(i - 1, j))
	{
		dfs(i - 1, j);
	}
	if (check(i + 1, j))
	{
		dfs(i + 1, j);
	}
	if (check(i, j - 1))
	{
		dfs(i, j - 1);
	}
	if (check(i, j + 1))
	{
		dfs(i, j + 1);
	}
}

void XuLy()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (check(i, j))
			{
				dfs(i, j);
				++ans;
			}
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
