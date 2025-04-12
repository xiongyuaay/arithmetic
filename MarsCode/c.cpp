/* 两个数按位异或是指将这两个数转换成二进制后，最低位与最低位异或作为结果的最低位，次低位与次低位异或作为结果的次低位，以此类推。

例如，3 与 5 按位异或值为 6 。

请问，有多少个不超过 2024 的正整数，与 2024 异或后结果小于 2024 。 */

#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    cout<<(3^5)<<std::endl;
    for (int i = 1; i < 2025; i++)
    {
        if ((i ^ 2024) < 2024)
        {
            count++;
        }
        
    }
    cout<<count<<endl;
    return 0;
    
}