/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        ListNode *prev = nullptr;
        ListNode *head = list1 ? list1 : list2;

        while (curr1 != nullptr)
        {
            if (curr2 == nullptr)
            {
                return head;
            }
            
            if (curr1->val >= curr2->val)
            {
                ListNode* temp = curr2->next;
                curr2->next = curr1;
                if (prev)
                {
                    prev->next = curr2;
                    prev = curr2;
                }
                else
                {
                    head = list2;
                    prev = curr2;
                }
                
                
                curr2 = temp;
            }
            else
            {
                prev = curr1;
                curr1 = curr1->next;
            }
            
            
        }
        if (prev)
        {
            prev->next = curr2;
        }
        return head;
        
        
    }
};

