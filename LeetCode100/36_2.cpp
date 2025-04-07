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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* predessesor = nullptr;
        while (root)
        {
            if (root->left)
            {
                predessesor = root->left;
                while (predessesor->right != nullptr && predessesor->right != root)
                {
                    predessesor = predessesor->right;
                }

                if (predessesor->right == nullptr)
                {
                    predessesor->right = root;
                    root = root->left;
                }
                else
                {
                    res.push_back(root->val);
                    predessesor->right = nullptr;
                    root = root->right;
                }
            }
            else
            {
                res.push_back(root->val);
                root = root->right;
            }
                        
        }
        return res;
        
    }

};