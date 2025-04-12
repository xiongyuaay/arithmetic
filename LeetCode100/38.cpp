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
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return root;
        }
        
        queue<TreeNode*> cas;
        cas.push(root);
        TreeNode* curr;

        while (cas.size() != 0)
        {
            curr = cas.front();
            cas.pop();
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if (curr->left)
            {
                cas.push(curr->left);
            }
            if (curr->right)
            {
                cas.push(curr->right);
            }
            
            
        }
        return root;
    }
};