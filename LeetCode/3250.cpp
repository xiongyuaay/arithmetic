/* 给你一个长度为 n 的 正 整数数组 nums 。

如果两个 非负 整数数组 (arr1, arr2) 满足以下条件，我们称它们是 单调 数组对：

两个数组的长度都是 n 。
arr1 是单调 非递减 的，换句话说 arr1[0] <= arr1[1] <= ... <= arr1[n - 1] 。
arr2 是单调 非递增 的，换句话说 arr2[0] >= arr2[1] >= ... >= arr2[n - 1] 。
对于所有的 0 <= i <= n - 1 都有 arr1[i] + arr2[i] == nums[i] 。
请你返回所有 单调 数组对的数目。

由于答案可能很大，请你将它对 109 + 7 取余 后返回。 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int res = countOfcurr(nums, 0, nums[0], 0);
        return res;
    }

    int countOfcurr(vector<int>& nums, int min, int max, int curr)
    {
        int num = nums[curr];
        if (min > num || (num - max) < 0)
        {
            return 0;
        }
        
        int bound = min > (num - max) ? min : (num - max);
        if (curr == nums.size() - 1)
        {
            int res = num - bound + 1;
            // cout<<res<<endl;
            return res;
        }

        int total = 0;
        for (int i = bound; i <= num; i++)
        {
            // cout<<"("<<i<<(nums[curr] - i)<<')';
            total += countOfcurr(nums, i, num - i, curr+1);
        }
        
        return total;
    }
};

int main()
{
    vector<int> nums = {2, 3, 2};
    Solution s;
    s.countOfPairs(nums);
    return 0;
}