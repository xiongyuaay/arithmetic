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
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        

        if (root->left)
        {
            TreeNode* curr = root->left;
            while (curr != nullptr)
            {
                if (curr->val >= root->val)
                {
                    return false;
                }
                curr = curr->right;
            }
            
            
        }
        
        if (root->right)
        {
            TreeNode* curr = root->right;
            while (curr != nullptr)
            {
                if (curr->val <= root->val)
                {
                    return false;
                }
                curr = curr->left;
            }
            
        }

        return isValidBST(root->left) && isValidBST(root->right);
        
    }
};