#include <string>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) 
    {
        int a[] = {coordinate1[0] - 'a' + 1, coordinate1[1] - '0'};
        int b[] = {coordinate2[0] - 'a' + 1, coordinate2[1] - '0'};

        if ((a[0] + a[1]) % 2 == (b[0] + b[1]) % 2)
        {
            return true;
        }
        
        return false;
    }
};