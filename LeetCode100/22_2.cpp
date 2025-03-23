/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution 
{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            unordered_set<ListNode*> visited;
            ListNode* curr = headA;
            while (curr != nullptr)
            {
                visited.insert(curr);
                curr = curr->next;
            }

            curr = headB;
            while (curr != nullptr)
            {
                if (visited.find(curr) != visited.end())
                {
                    return curr;
                }
                curr = curr->next;
                
            }
            return nullptr;
            

        }
};