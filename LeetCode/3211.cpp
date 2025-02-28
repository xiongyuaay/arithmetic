#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> R;
        R.push_back("0");
        R.push_back("1");
        for(int i=1;i<n;i++)
        {
            int size = R.size();
            for(int j=0;j<size;j++)
            { 
                if(R[j].back() == '1')
                {
                    R.push_back(R[j] + "1");
                    R[j] = R[j] + "0";
                }
                else
                {
                    R[j] = R[j] + "1";
                }
            }
        }

        return R;
        
    }
};

int main()
{
    Solution s;
    vector<string> R;
    R = s.validStrings(3);
    for(auto &r:R)
    {
        cout<<r<<' '<<endl;
    }
    return 0;
}