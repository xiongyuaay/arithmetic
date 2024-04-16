#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 算法要求：请编写一段代码，能够在最坏情况下用 O(n)时间找出 n 个元素的带权中位数
// 函数原型： 
int Select(vector<int>num,vector<int>sub, int p, int r, int k)
{
    if((r-p-4)/5<=1)
    {
        return sub[p];
    }
    for(int i=0;i<=(r-p-4)/5;i++)
    {
        
        for(int m=0;m<5;m++)
        {
            int greater = 0;
            int lower = 0;
            for(int n = p+5*i;n<=p+5*i+4;n++)
            {
                if(num[n]>=num[p+5*i+m])
                {
                    lower++;
                }
                if(num[n]<=num[p+5*i+m])
                {
                    greater++;
                }
            }
            if(greater>=3&&lower>=3)
            {
                int temp_num = num[p+5*i+m];
                num[p+5*i+m] = num[p+i];
                num[p+i] = temp_num;
                int temp_sub = sub[p+5*i+m];
                sub[p+5*i+m] = sub[p+i];
                sub[p+i] = temp_sub;
                break;
            }
        }
    }
    Select

}






void WeightMedian(int length,vector<int>num, vector<double>weight,int index){
    int p = 1; // selected number
    int i = 0;
    int j = length;
    int x = num[p];
    num[p] = num[i];
    num[i] = x;
    double temp2 = weight[i];
    weight[i] = weight[p];
    weight[p] = temp2;
    double left = 0;
    while(true)
    {
        while(num[++i] < x && i < length-1);
        while(num[--j] > x);
        if(i >= j) break;
        int temp1 = num[i];
        num[i] = num[j];
        num[j] = temp1;
        double temp2 = weight[i];
        weight[i] = weight[j];
        weight[j] = temp2;
    }
    num[0] = num[j];
    num[j] = x;
    double temp_w = weight[0];
    weight[0] = weight[j];
    weight[j] = temp_w;
    i = 0;
    while(num[i] < x)
    {
        left += weight[i];
        i++;
    }
    if(left <= 0.5 && left+weight[j] >= 0.5)
    {
        cout<<num[j]<<endl<<index;
        return;
    }
    if(left < 0.5)
    {
        weight[j] += left;
        auto start1 = num.begin() + j;
        auto end1 = num.begin() + length;
        vector<int> Newnum(start1, end1);
        auto start2 = weight.begin() + j;
        auto end2 = weight.begin() + length;
        vector<double> Newweight(start2, end2);
        WeightMedian(length-j, Newnum, Newweight, index+1);
    }
    if(left > 0.5)
    {
        auto start1 = num.begin();
        auto end1 = num.begin() + j;
        vector<int> Newnum(start1, end1);
        auto start2 = weight.begin();
        auto end2 = weight.begin() + j;
        vector<double> Newweight(start2, end2);
        WeightMedian(j, Newnum, Newweight, index+1);
    }
}
//你的代码只需要补全上方函数来实现算法
//其中length为输入长度，num是包含n个互不相同元素值的向量，weight是包含元素值对应的权重的向量，index为递归调用时的索引(下标)
//只需要提交这几行代码，其他的都是后台系统自动完成的。类似于 LeetCode
int main() {

    // 后台自动给出测试代码放在这里，无需同学编写

    //测试代码将测试用例的三行数据分别导入length，num，和weight中

    //调用WeightMedian(length,num, weight,index)函数，函数内部使用cout输出得到的中位数，测试代码默认index初始值为0
    vector<int> num = {1, 9, 6, 3, 0, 2, 8};
    vector<double> weight = {0.1, 0.15, 0.4, 0.2, 0.0, 0.05, 0.1};
    WeightMedian(num.size(), num, weight, 0);
    return 0;

}