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
    vector<int> nums;

public:
    bool isSymmetric(TreeNode* root) {
        Morris(root);
        int size = nums.size();

        for (int i = 0, j = size - 1; i < size / 2; i++, j--)
        {
            if (nums[i] != nums[j])
            {
                return false;
            }
            
        }
        return true;
    }

    void Morris(TreeNode* root)
    {
        TreeNode* precedessor;

        while (root)
        {
            if (root->left)
            {
                precedessor = root->left;
                while (precedessor->right != nullptr && precedessor->right != root)
                {
                    precedessor = precedessor->right;
                }
                
                if (precedessor->right == nullptr)
                {
                    precedessor->right = root;
                    root = root->left;
                }
                else
                {
                    nums.push_back(root->val);
                    precedessor->right = nullptr;
                    root = root->right;
                }
            }
            else
            {
                nums.push_back(root->val);
                root = root->right;
            }
            
            
            
            
        }
        
    }
};