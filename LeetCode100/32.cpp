/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#include<vector>
#include<array>
#include<utility>
#include<unordered_map>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
        {
            return nullptr;
        }
        
        vector<pair<int, Node*>> vec;
        unordered_map<Node*, int> p2i;

        int count = 0;
        while (head)
        {
            p2i[head] = count;
            count++;
            vec.push_back({head->val, head->random});
            head = head->next;
        }

        vector<Node*> table;

        Node* newhead = new Node(vec[0].first);
        Node* curr = newhead;
        table.push_back(newhead);
        for (int i = 1; i < count; i++)
        {
            curr->next = new Node(vec[i].first);
            curr = curr->next;
            table.push_back(curr);
        }
        
        curr = newhead;
        for (int i = 0; i < count; i++)
        {
            if (vec[i].second == nullptr)
            {
                curr->random = nullptr;
                curr = curr->next;
                continue;
            }
            
            curr->random = table[p2i[vec[i].second]];
            curr = curr->next;
        }
        
        return newhead;
    }
};

Node* generate(vector<pair<int, int>> vec)
{
    vector<Node*> i2p;
    Node *head = new Node(vec[0].first);
    Node *curr = head;
    int size = vec.size();
    for (int i = 0; i < size - 1; i++)
    {
        i2p.push_back(curr);
        curr->next = new Node(vec[i+1].first);
        curr = curr->next;
    }
    i2p.push_back(curr);
    curr = head;
    for (int i = 0; i < size; i++)
    {
        if (vec[i].second == -1)
        {
            curr->random = nullptr;
            curr = curr->next;
            continue;
        }
        
        curr->random = i2p[vec[i].second];
        curr = curr->next;
    }
    
    return head;
    
}

int main()
{
    Solution s;
    vector<pair<int, int>> vec = {{7,-1},{13,0},{11,4},{10,2},{1,0}};
    Node* head = generate(vec);
    Node* newhead = s.copyRandomList(head);

    return 0;
}