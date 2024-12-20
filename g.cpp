#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int res = 2147483647;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        if (temp % 2 == 0 && temp < res)
        {
            res = temp;
        }
    }
    cout<<res<<endl;
    return res;
    
}