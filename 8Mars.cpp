/* 小R从班级中抽取了一些同学，每位同学都会给出一个数字。已知在这些数字中，某个数字的出现次数超过了数字总数的一半。现在需要你帮助小R找到这个数字。 */


#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    map<int, int> count;
    int max = array[0];
    for (auto &num:array)
    {
        count[num]++;
        if (count[max] < count[num])
        {
            max = num;
        }
        
    }
    
    
    return max;
}

int main() {
    // Add your test cases here
    
    cout << (solution({1, 3, 8, 2, 3, 1, 3, 3, 3}) == 3) << endl;
    
    return 0;
}
