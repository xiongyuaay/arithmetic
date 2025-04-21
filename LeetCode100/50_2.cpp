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
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int cur;
    int res;

public:
    int maxPathSum(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> mymap;

        int result = INT_MIN;

        q.push(root);

        while (q.size())
        {
            TreeNode* curr = q.front();
            q.pop();
            cur = 0;
            res = INT_MIN;
            preOrder(curr);
            mymap[curr] = res;
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        q.push(root);
        while (q.size())
        {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left && curr->right)
            {
                int temp = mymap[curr->left] + curr->val + mymap[curr->right];
                mymap[curr] = mymap[curr] >= temp ? mymap[curr] : temp; 
            }

            result = result >= mymap[curr] ? result : mymap[curr];
            
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        
        return result;
    }

    void preOrder(TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        cur += root->val;
        if (cur > res)
        {
            res = cur;
        }
        
        preOrder(root->left);
        if (root->left)
        {
            cur -= root->left->val;
        }

        preOrder(root->right);
        if (root->right)
        {
            cur -= root->right->val;
        }
        return;
    }

};