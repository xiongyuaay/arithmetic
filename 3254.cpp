/* 给你一个长度为 n 的整数数组 nums 和一个正整数 k 。

一个数组的 能量值 定义为：

如果 所有 元素都是依次 连续 且 上升 的，那么能量值为 最大 的元素。
否则为 -1 。
你需要求出 nums 中所有长度为 k 的 
子数组
 的能量值。

请你返回一个长度为 n - k + 1 的整数数组 results ，其中 results[i] 是子数组 nums[i..(i + k - 1)] 的能量值。 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> jump;
        vector<int> results;
        for(int i=1;i<n;i++)
        {
            if(nums[i] != nums[i-1] + 1)
            {
                jump.push_back(i);
            }
        }
        jump.push_back(n);
        for(int i=0, j=0;i<n-k+1;)
        {
            if(i+k-1 < jump[j])
            {
                results.push_back(nums[i+k-1]);
                i++;
                continue;
            }
            if(i < jump[j] && jump[j] <= i+k-1)
            {
                results.push_back(-1);
                i++;
                continue;
            }
            if(i >= jump[j] && j < jump.size() - 1)
            {
                j++;
            }

        }
        return results;
    }
};

int main()
{
    Solution s;
    vector<int> results;
    vector<int> nums = {1, 2, 3, 4, 3, 2, 5};
    results = s.resultsArray(nums, 3);

    return 0;
}