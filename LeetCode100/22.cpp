/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution 
{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *currA = headA;

            while (currA != nullptr)
            {
                ListNode *currB = headB;
                while (currB != nullptr)
                {
                    if (currA == currB)
                    {
                        return currA;
                    }
                    currB = currB->next;

                }
                currA = currA->next;
                
            }
            return nullptr;

        }
};