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
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = new ListNode();
        prev->next = head;
        ListNode *head1 = prev;
        ListNode *curr1 = head;
        ListNode *curr2 = head ? head->next:nullptr;
        if (curr2 == nullptr)
        {
            return head;
        }

        while (curr2)
        {
            prev->next = curr2;
            curr1->next = curr2->next;
            curr2->next = curr1;

            prev = curr1;
            curr1 = curr1->next;
            if (!curr1)
            {
                break;
            }
            
            if (curr1->next)
            {
                curr2 = curr1->next;
            }
            else
            {
                break;
            }
            
        }
        return head1->next;

        
    }
};

ListNode *generate(int* nums, int length)
{
    ListNode *head = new ListNode();
    ListNode *curr = head;

    for (int i = 0; i < length - 1; i++)
    {
        curr->val = nums[i];
        curr->next = new ListNode();
        curr = curr->next;
    }
    curr->val = nums[length - 1];
    return head;
}

int main()
{
    Solution s;
    int nums1[4] = {1, 2, 3, 4};

    ListNode* l1 = generate(nums1, 4);

    ListNode* res = s.swapPairs(l1);
    return 0;


}