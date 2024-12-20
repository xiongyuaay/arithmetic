#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(const vector<vector<int>> &prefix, int x1, int y1, int x2, int y2) 
{
    int result = prefix[x2][y2];
    if (x1 > 0) result -= prefix[x1 - 1][y2];
    if (y1 > 0) result -= prefix[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) result += prefix[x1 - 1][y1 - 1];
    return result;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> prefix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            prefix[i][j] = a[i][j];
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    int maxSum = INT_MIN;

    for (int x1 = 0; x1 < n; x1++) 
    {
        for (int y1 = 0; y1 < m; y1++) 
        {
            for (int d = 1; x1 + d < n && y1 + d < m; d++) 
            {
                int x2 = x1 + d, y2 = y1 + d;

                int top = getSum(prefix, x1, y1, x1, y2); 
                int bottom = getSum(prefix, x2, y1, x2, y2); 
                int left = getSum(prefix, x1, y1, x2, y1);
                int right = getSum(prefix, x1, y2, x2, y2); 
                
                int total = top + bottom + left + right;
                total -= a[x1][y1] + a[x1][y2] + a[x2][y1] + a[x2][y2];

                maxSum = max(maxSum, total);
            }
        }
    }

    cout << maxSum << endl;
    return 0;
}
