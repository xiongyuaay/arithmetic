#include<iostream>
#include<set>
#include<unordered_map>
#include<utility>

using namespace std;

class LRUCache {
private:
    int count;
    unordered_map<int, pair<int, int>> dict;
    int size;

public:
    LRUCache(int capacity) {
        count = 0;
        size = capacity;
    }
    
    int get(int key) {
        if (dict.count(key))
        {
            count++;
            dict[key].second = count;
            return dict[key].first;
        }
        else
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        count++;
        if (dict.size() < size)
        {
            dict[key] = {value, count};
        }
        else
        {
            if (dict.count(key))
            {
                dict[key] = {value, count};
                return;
            }
            
            int min = 0;
            int minCount = count;
            for (auto &pair:dict)
            {
                if (pair.second.second < minCount)
                {
                    min = pair.first;
                    minCount = pair.second.second;
                }
                
            }
            dict.erase(min);
            dict[key] = {value, count};
            
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache lru(2);
    lru.get(2);
    lru.put(2, 6);
    lru.get(1);
    lru.put(1, 5);
    lru.put(1, 2);
    lru.get(1);
    int res = lru.get(2);
    cout<<res<<endl;
    return 0;

}