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

#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head)
        {
            return nullptr;
        }
        
        vector<ListNode*> vec;
        while (head)
        {
            vec.push_back(head);
            head = head->next;
        }

        sort(vec.begin(), vec.end(), cmp);

        head = vec[0];
        int count = vec.size();
        for (int i = 0; i < count - 1; i++)
        {
            head->next = vec[i+1];
            head = head->next;
        }
        head->next = nullptr;
        return vec[0];
    }

    static bool cmp(ListNode* a, ListNode* b)
    {
        return a->val < b->val;
    }
};