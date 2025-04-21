/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode* res = BST(nums, 0, nums.size() - 1);

        return res;
    }

    TreeNode* BST(vector<int>& nums, int start, int end)
    {
        if (start == end)
        {
            return new TreeNode(nums[start]);
        }
        if (start > end)
        {
            return nullptr;
        }
        
        
        int mid = (end - start) / 2 + start;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BST(nums, start, mid - 1);
        root->right = BST(nums, mid + 1, end);

        return root;
    }
};