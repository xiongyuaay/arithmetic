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
        if (inorder.size() == 0)
        {
            return nullptr;
        }
        int count = preorder.size();
        TreeNode* root;
        int id;

        for (int i = 0; i < count; i++)
        {
            if (find(inorder.begin(), inorder.end(), preorder[i]) != inorder.end())
            {
                root = new TreeNode(preorder[i]);
                id = preorder[i];
                preorder.erase(preorder.begin() + i);
                break;
            }
            
        }
        
        auto it = find(inorder.begin(), inorder.end(), id);


        vector<int> subIn1(inorder.begin(), it);
        vector<int> subIn2(it+1, inorder.end());
        
        root->left = buildTree(preorder, subIn1);
        root->right = buildTree(preorder, subIn2);

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