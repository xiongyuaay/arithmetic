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

#include<vector>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0)
        {
            return nullptr;
        }
        if (size == 1)
        {
            return lists[0];
        }

        while (lists.size() >= 2)
        {
            ListNode* l1 = lists[0];
            ListNode* l2 = lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());

            lists.push_back(merge2(l1, l2));
        }
        
        return lists[0];
        
        
    }

    ListNode* merge1(ListNode* l1, ListNode* l2)
    {
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }

        if (l1->val < l2->val)
        {
            l1->next = merge1(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge1(l1, l2->next);
            return l2;
        }
    }
    ListNode* merge2(ListNode* l1, ListNode* l2)
    {
        ListNode* preHead = new ListNode(-1);
        ListNode* prev = preHead;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
            
        }
        prev->next = l1 == nullptr? l2: l1;
        return preHead->next;
        
    }
};