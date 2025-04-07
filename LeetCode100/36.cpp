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
#include<vector>
using namespace std;
class Solution {
private:
    vector<int> *ptr; 
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        ptr = &res;

        inorder(root);
        return res;
    }

    void inorder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        
        if (root->left == nullptr)
        {
            ptr->push_back(root->val);
            inorder(root->right);
        }
        else
        {
            inorder(root->left);
            ptr->push_back(root->val);
            inorder(root->right);
        }
        
        
    }

};