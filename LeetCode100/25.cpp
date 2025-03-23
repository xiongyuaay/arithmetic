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
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while (head != nullptr)
        {
            if (visited.count(head))
            {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }
        return false;
        
    }
};