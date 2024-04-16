#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 算法要求：请编写⼀个算法，能够确定⼀个切割方案，使切割的总代价最⼩。
// 函数原型： 
int partition(int a[], int p, int r)
{
    int i = p;
    int j = r+1;
    int x = a[p];
    while(true)
    {
        while(a[++i]<x&&i<j);
        while(a[--j]>x);
        if(i>=j)
        {
            break;
        }
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}

void QuickSort(int a[], int p, int r)
{
    if(p<r)
    {
        int q = partition(a, p ,r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    }
}

void MinCost(int L,int n,int *p){
    QuickSort(p, 0, n+1);
    int **m = new int*[n+2];
    for(int i = 0;i<n+2;i++)
    {
        m[i] = new int[n+2];
        for(int j=0;j<n+2;j++)
        {
            m[i][j] = 0;
        }
    }
    for(int i=0;i<n+1;i++)
    {
       m[i][i+1] = 0; 
    }
    for(int r=3;r <= n+2;r++)
    {
        for(int i=0;i<=n-r+2;i++)
        {
            int j=i+r-1;
            m[i][j] = m[i+1][j] + p[j]-p[i];
            for(int k = i+1;k<j;k++)
            {
                int u = m[i][k] + m[k][j] + p[j]-p[i];
                if(u < m[i][j])
                {
                    m[i][j] = u;
                }
            }
        }
    }
    cout<<m[0][n+1];
}

//你的代码只需要补全上方函数来实现算法,可根据自己需要建立别的函数
//其中L是钢条长度，n是位置点个数，p包含n 个切割点的位置（乱序）
//只需要提交这几行代码，其他的都是后台系统自动完成的。类似于 LeetCode

int main() {

    // 后台自动给出测试代码放在这里，无需同学编写
    int L, n;
    cin>>L>>n;
    int *p;
    p = new int[n+2];
    p[0] = 0;
    p[n+1] = L;
    for(int i=1;i<n+1;i++){
        cin>>p[i];
    }
    MinCost(L,n,p);//调用函数输出一个切割最小的代价和，结果通过cout输出，均为int类型
    return 0;

}

