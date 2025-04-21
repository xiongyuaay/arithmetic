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

#include <queue>
#include <climits>
using namespace std;

class Solution {
private:
    int cur;
    int res;

public:
    int maxPathSum(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        queue<TreeNode*> q;
        int result = INT_MIN;

        q.push(root);

        while (q.size())
        {
            TreeNode* curr = q.front();
            q.pop();
            cur = 0;
            res = 0;
            preOrder(curr);
            if (res > result)
            {
                result = res;
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        return result;
    }

    void preOrder(TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        cur += root->val;
        if (cur > res)
        {
            res = cur;
        }
        
        preOrder(root->left);
        if (root->left)
        {
            cur -= root->left->val;
        }

        preOrder(root->right);
        if (root->right)
        {
            cur -= root->right->val;
        }
        return;
    }

};