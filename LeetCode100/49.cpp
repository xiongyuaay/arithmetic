/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <vector>
using namespace std;

class Solution {
private:
    vector<TreeNode*> curr;
    TreeNode* target;
    TreeNode* res;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        target = nullptr;
        preOrder(root, p, q);
        return res;
    }

    void preOrder(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
        {
            return;
        }

        curr.push_back(root);
        
        if (target == nullptr && (root == p || root == q))
        {
            target = root;
        }
        if (target != nullptr && (root == p || root == q))
        {
            res = target;
        }

        if (root->left)
        {
            preOrder(root->left, p, q);
            if (curr.back() == target)
            {
                curr.pop_back();
                target = curr.back();
            }
            else
            {
                curr.pop_back();
            }
        }
        if (root->right)
        {
            preOrder(root->right, p, q);
            if (curr.back() == target)
            {
                curr.pop_back();
                target = curr.back();
            }
            else
            {
                curr.pop_back();
            }
        }
        
        


        
        
    }
};