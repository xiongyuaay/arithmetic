#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int H, int A, vector<int> h, vector<int> a) {
    // write code here
    int res = 0;
    int pre_h = -1;
    int pre_a = -1;
    for (int i = 0; i < n; i++)
    {
        int h_cur = h[i];
        int a_cur = a[i];
        if (h_cur <= pre_h || a_cur <= pre_a || A <= a_cur || H <= h_cur)
        {
            continue;
        }
        res++;
        pre_h = h_cur;
        pre_a = a_cur;
    }
    


    return res;
}

int main() {
    cout << (solution(3, 4, 5, {1, 2, 3}, {3, 2, 1}) == 1) << endl;
    cout << (solution(5, 10, 10, {6, 9, 12, 4, 7}, {8, 9, 10, 2, 5}) == 2) << endl;
    cout << (solution(4, 20, 25, {10, 15, 18, 22}, {12, 18, 20, 26}) == 3) << endl;
    return 0;
}