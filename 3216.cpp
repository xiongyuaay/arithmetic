#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        int length = s.size();
        for(int i=1;i<length;i++)
        {
            for(int j=0;j<length-1;j++)
            {
                if(s[j] > s[j+1] && ((s[j] - '0')%2 == (s[j+1] - '0')%2))
                {
                    char temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
                    return s;
                }
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout<<s.getSmallestString("45320");
    return 0;
}