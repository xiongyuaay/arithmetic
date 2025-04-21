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
#include <queue>
using namespace std;
class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            if (!root)
            {
                return res;
            }
            
            queue<TreeNode*> cascade;
            TreeNode* SCO = new TreeNode();
            cascade.push(root);
            cascade.push(SCO);
            vector<int> level;

            while (cascade.size())
            {
                TreeNode* curr = cascade.front();
                cascade.pop();
                if (curr == SCO)
                {
                    res.push_back(level);
                    level.clear();
                    if (cascade.size() == 0)
                    {
                        return res;
                    }
                    cascade.push(SCO);
                    continue;
                }
                
                level.push_back(curr->val);
                if (curr->left)
                {
                    cascade.push(curr->left);
                }
                if (curr->right)
                {
                    cascade.push(curr->right);
                }
                
                
            }
            return res;
            
        }
    };