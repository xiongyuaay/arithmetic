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
private:
    vector<TreeNode*> seq;
public:
    void flatten(TreeNode* root) {
        if (!root)
        {
            return;
        }
        beforOrder(root);
        int count = seq.size();

        for (int i = 0; i < count - 1; i++)
        {
            seq[i]->right = seq[i+1];
            seq[i]->left = nullptr;
        }
        seq[count-1]->left = nullptr;
        seq[count-1]->right = nullptr;
        return;
        
        
    }

    void beforOrder(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        
        seq.push_back(root);
        beforOrder(root->left);
        beforOrder(root->right);

        return;
    }
    
};