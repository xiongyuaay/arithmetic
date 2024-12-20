/* 如果一个数 p 是个质数，同时又是整数 a 的约数，则 p 称为 a 的一个质因数。

请问， 2024 的最大的质因数是多少？ */

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v(2025, 0);
    int max = 2;
    for (int i = 2; i <= 2024; i++)
    {
        if (v[i] == 0)
        {
            if (2024 % i == 0)
            {
                if (i > max)
                {
                    max = i;
                }
                
            }
            
            for (int j = 2*i; j <= 2024; j+=i)
            {
                v[j] = 1;
            }
            
        }
        
    }
    cout<<max<<endl;
    return 0;
}