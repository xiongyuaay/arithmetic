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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
        {
            return res;
        }
        int count = 0;
        while (root)
        {
            TreeNode* curr = root;
            vector<int> temp;
            while (curr)
            {
                temp.push_back(curr->val);
                if (curr->right)
                {
                    curr = curr->right;
                    continue;
                }
                else
                {
                    curr = curr->left;
                }
            }
            int size = temp.size();

            for (int i = res.size() - count; i < size; i++)
            {
                res.push_back(temp[i]);
            }
            count++;
            root = root->left;
            
        }
        
        
        return res;
        
        
    }
};