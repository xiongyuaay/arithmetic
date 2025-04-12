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

#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        deque<TreeNode*> cascade;
        cascade.push_back(root);

        while (cascade.size())
        {
            TreeNode* curr = cascade.front();
            cascade.pop_front();

            if (curr->left)
            {
                cascade.push_back(curr->left);
            }
            if (curr->right)
            {
                cascade.push_back(curr->right);
            }

            res = max(res, diameterOfRoot(curr));
            
            
        }
        


        return res;
    }

    int diameterOfRoot(TreeNode* root)
    {
        return getDepth(root->left) + getDepth(root->right);
    }

    int getDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        else
        {
            return 1+std::max(getDepth(root->left), getDepth(root->right));
        }
        
        
    }

    
};

#include <vector>
#include <iostream>
using namespace std;

TreeNode* generate(vector<int> nums)
{
    int size = nums.size();

    vector<TreeNode*> tree;

    for (int i = 0; i < size; i++)
    {
        tree.push_back(new TreeNode(nums[i]));
    }

    for (int i = 0; i < size; i++)
    {
        if (2*i+1 >= size)
        {
            break;
        }
        
        tree[i]->left = tree[2*i+1];
        if (2*i+2 >= size)
        {
            break;
        }
        
        tree[i]->right = tree[2*i+2];

    }
    return tree[0];
    
    
}


int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    TreeNode* root = generate(nums);
    Solution s;

    int res = s.diameterOfBinaryTree(root);
    cout<<res<<endl;
    return res;
}