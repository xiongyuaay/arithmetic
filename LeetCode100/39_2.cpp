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

#include <deque>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* SCO = new TreeNode();
        deque<TreeNode*> cascade;
        cascade.push_back(root);
        cascade.push_back(SCO);

        while (cascade.size())
        {
            TreeNode* curr = cascade.front();
            cascade.pop_front();

            if (curr != SCO && curr != nullptr)
            {
                cascade.push_back(curr->left);
                cascade.push_back(curr->right);
                continue;
            }

            if (curr == SCO)
            {
                int size = cascade.size();
                if(size == 0)
                {
                    break;
                }
                for (int i = 0, j = size - 1; i < size/2; i++, j--)
                {
                    if (cascade[i] == nullptr)
                    {
                        if (cascade[j] == nullptr)
                        {
                            continue;
                        }
                        else
                        {
                            return false;
                        }
                        
                    }
                    else
                    {
                        if (cascade[j] == nullptr || cascade[i]->val != cascade[j]->val)
                        {
                            return false;
                        }
                        
                    }
                    
                    
                }
                cascade.push_back(SCO);

                
            }
            
            

        }
        return true;
    }
};