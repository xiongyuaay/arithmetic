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
class Solution {
private:
    int count;
    int target;
    int res;

public:
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        count = 0;
        res = root->val;
        inOrder(root);
        return res;
    }

    void inOrder(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        
        inOrder(root->left);
        count++;
        if (count == target)
        {
            res = root->val;
        }
        inOrder(root->right);
        
    }
};