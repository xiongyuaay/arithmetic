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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *countN = nullptr;
        ListNode *countN1 = nullptr;
        ListNode *temp = head;

        int curr = 0;

        while (temp != nullptr)
        {
            curr++;
            if (curr == n)
            {
                countN = head;
                countN1 = nullptr;
            }
            if (curr > n)
            {
                countN1 = countN;
                countN = countN->next;
            }
            
            temp = temp->next;

        }
        if (countN1 == nullptr)
        {
            return head->next;
        }
        
        if (countN->next)
        {
            countN1->next = countN->next;
        }
        else
        {
            countN1->next = nullptr;
        }
        return head;
        
        
    }
};