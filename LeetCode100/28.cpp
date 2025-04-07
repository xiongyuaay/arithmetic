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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode *curr1 = l1, *curr2 = l2;

        while (curr1 != nullptr)
        {
            int next_c = (curr1->val + curr2->val + c) / 10;
            curr1->val = (curr1->val + curr2->val + c) % 10;
            c = next_c;

            if (curr1->next == nullptr)
            {
                curr1->next = curr2->next;
                while (c)
                {
                    if (c && !curr1->next)
                    {
                        curr1->next = new ListNode(c);
                        return l1;
                    }
                    
                    curr1 = curr1->next;
                    next_c = (curr1->val + c) / 10;
                    curr1->val = (curr1->val + c) % 10;
                    c = next_c;

                }
                return l1;
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
            if (curr2 == nullptr)
            {
                while (c)
                {
                    next_c = (curr1->val + c) / 10;
                    curr1->val = (curr1->val + c) % 10;
                    c = next_c;
                    if (c && !curr1->next)
                    {
                        curr1->next = new ListNode(c);
                        return l1;
                    }
                    
                    curr1 = curr1->next;

                }
                return l1;
                
            }
            
            
            
        }
        return l2;
        
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
    int nums1[3] = {2, 4, 9};
    int nums2[4] = {5, 6, 4, 9};

    ListNode* l1 = generate(nums1, 3);
    ListNode* l2 = generate(nums2, 4);

    ListNode* res = s.addTwoNumbers(l1, l2);
    return 0;


}

