#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
using namespace std;

#define int long long
const int MAXN = 5e3 + 7;
int x[MAXN];
array<int, 2> dp[MAXN][MAXN];
int n;

void XuLy()
{
    cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = n - 1; ~i; --i)
	{
		for (int j = i; j < n; ++j)
		{
			array<long long, 2> temp;
			if (i == j)
			{
				temp = {x[i], 0};
			}
			else
			{
				if (dp[i + 1][j][1] + x[i] > dp[i][j - 1][1] + x[j])
				{
					temp = {dp[i + 1][j][1] + x[i], dp[i + 1][j][0]};
				}
				else
				{
					temp = {dp[i][j - 1][1] + x[j], dp[i][j - 1][0]};
				}
			}
			dp[i][j] = temp;
		}
	}
	cout << dp[0][n - 1][0];
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
