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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummynode = new ListNode(0, head);
        ListNode* curr0 = dummynode;
        ListNode* currk1 = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;


        while (curr != nullptr)
        {
            ListNode* temp = curr;
            for (int i = 0; i < k; i++)
            {
                if (!temp)
                {
                    return dummynode->next;
                }
                
                temp = temp->next;
            }
            currk1 = temp;
            prev = currk1;

            for (int i = 0; i < k; i++)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            temp = curr0->next;
            curr0->next = prev;
            curr0 = temp;
        }
        return dummynode->next;

    }
};