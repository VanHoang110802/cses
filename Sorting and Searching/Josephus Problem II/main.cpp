#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

void XuLy()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > arr;
    int root = sqrt(n);
    int row = 0, col = 0, count = 0;
    vector<int> vec;
    for(int i = 1; i <= n; i++)
    {
        if(count > root)
        {
            count = 0;
            arr.push_back(vec);
            vec.clear();
        }
        vec.push_back(i);
        count++;
    }
    if(!vec.empty())
    {
        arr.push_back(vec);
    }

    for(int i = 0; i < n; i++)
    {
        int j = k % (n - i);
        while(j)
        {
            if(col + j < arr[row].size())
            {
                col += j;
                j = 0;
            }
            else
            {
                j -= arr[row].size() - col;
                col = 0;
                row++;
            }
            if(row >= arr.size())
            {
                row = 0;
            }
        }

        while(arr[row].size() <= col)
        {
            col = 0;
            row++;
            if(row >= arr.size())
            {
                row = 0;
            }
        }
        cout << arr[row][col] << ' ';
        if(i != n - 1)
        {
            arr[row].erase(arr[row].begin() + col);
            while(arr[row].size() <= col)
            {
                col = 0;
                row++;
                if(row >= arr.size())
                {
                    row = 0;
                }
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

//    int test;
//    cin >> test;
//    while(test--)
    XuLy();

    cout << "\n\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.";
    return 0;
}
