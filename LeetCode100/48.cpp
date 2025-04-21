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

#include <queue>
#include <iostream>
#include <limits>
using namespace std;

int minVal = std::numeric_limits<int>::min();

class Solution {
private:
    int count;
    int target;
    long long curSum;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
        {
            return 0;
        }
        
        int res = 0;
        target = targetSum;

        queue<TreeNode*> cascade;
        cascade.push(root);

        while (cascade.size())
        {
            TreeNode* curr = cascade.front();
            cascade.pop();

            count = 0;
            curSum = 0;

            preOrder(curr);
            res += count;

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

    void preOrder(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        curSum += root->val;
        if (curSum == target)
        {
            count++;
        }
        
        if (root->left)
        {
            preOrder(root->left);
            curSum -= root->left->val;
        }
        
        if (root->right)
        {
            preOrder(root->right);
            curSum -= root->right->val;
        }
        

        return;
    }



};

TreeNode* generate(vector<int> nums)
{
    int size = nums.size();

    vector<TreeNode*> tree;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == minVal)
        {
            tree.push_back(nullptr);
            continue;
        }
        
        tree.push_back(new TreeNode(nums[i]));
    }

    for (int i = 0; i < size; i++)
    {
        if (2*i+1 >= size)
        {
            break;
        }
        if (!tree[i])
        {
            continue;
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
    vector<int> nums = {10,5,-3,3,2,minVal,11,3,-2,minVal,1};
    TreeNode* root = generate(nums);
    Solution s;

    int res = s.pathSum(root, 8);
    cout<<res<<endl;
    return res;
}