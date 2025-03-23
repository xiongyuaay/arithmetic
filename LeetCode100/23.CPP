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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *last = head;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            if (curr == head)
            {
                curr->next = nullptr;
            }
            else
            {
                curr->next = last;
            }
            if (next == nullptr)
            {
                return curr;
            }
            
            
            last = next->next;
            next->next = curr;
            curr = last;
            last = next;
            
        }
        return last;
    }
};