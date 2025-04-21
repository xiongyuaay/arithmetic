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
#include <algorithm>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> subPre1;
        vector<int> subPre2;

        int id = preorder[0];
        auto it = find(inorder.begin(), inorder.end(), id);



        vector<int> subIn1(inorder.begin(), it);
        vector<int> subIn2(it+1, inorder.end());

        for (auto &num:preorder)
        {
            if (find(subIn1.begin(), subIn1.end(), num) != subIn1.end())
            {
                subPre1.push_back(num);
            }
            if (find(subIn2.begin(), subIn2.end(), num) != subIn2.end())
            {
                subPre2.push_back(num);
            }
        }
        
        root->left = buildTree(subPre1, subIn1);
        root->right = buildTree(subPre2, subIn2);

        return root;

    }
};

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution s;
    TreeNode* res = s.buildTree(preorder, inorder);
    return 0;

}