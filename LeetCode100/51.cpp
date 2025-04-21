#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if (r == 0)
        {
            return 0;
        }
        
        int c = grid[0].size();

        int res = 0;

        vector<pair<int, int>> last;
        vector<pair<int, int>> curr;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; i < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    pair<int, int> temp;
                    temp.first = j;
                    while (j < c && grid[i][j] == '1')
                    {
                        j++;
                    }
                    temp.second = j - 1;
                    curr.push_back(temp);
                    
                }
                
            }
            int pre = last.size();

            if (pre == 0)
            {
                res += curr.size();
                last = curr;
                curr.clear();
                continue;
            }
            vector<pair<int, int>> temp;
            temp.insert(temp.end(), curr.begin(), curr.end());
            temp.insert(temp.end(), last.begin(), last.end());

            last = curr;
            curr.clear();

            sort(temp.begin(), temp.end());

            vector<pair<int, int>> temp2;

            int first = temp[0].first;
            int second = temp[0].second;
            for (auto &p:temp)
            {
                if (second < p.first)
                {
                    temp2.push_back({first, second});
                    first = p.first;
                    second = p.second;
                }

                second = max(second, p.second);
                
            }
            res = res - pre + temp2.size();
        }
        

        return res;
        
    }
};

int main()
{
    Solution s;
    vector<vector<char>> nums({
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    });

    int num = s.numIslands(nums);

    return num;

}