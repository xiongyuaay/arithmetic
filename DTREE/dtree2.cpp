#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#include <limits>
const int Max = std::numeric_limits<int>::max();
 
// 算法要求：设计一个算法求 T 的最小顶点集合 S，使 T/S 为一个 d 森林。



class dTree
{
private:
    vector<vector<int>> edge;
    int td;
    int tn;

public:
    dTree(int n, int d) 
    { 
        //此处为构造函数，初始化构建树。
        
        edge.resize(n);
        for(auto &row : edge)
        {
            row.resize(n, Max);
        }
        int len;
        int adj;
        int weight;
        for(auto &row : edge)
        {
            cin>>len;
            for(int i=0;i<len;i++)
            {
                cin >> adj >> weight;
                row[adj] = weight;
            }
        }
        tn = n;
        td = d;
    }
    void solution();
    int GetCost(int node)
    {
        int max = 0;
        int temp = 0;
        for(int i=0;i<tn;i++)
        {
            if(edge[node][i] != Max)
            {
                temp = edge[node][i] + GetCost(i);
                if(temp > max)
                {
                    max = temp;
                }
            }
        }
        return max;
    }
    void DFS(int root, int &count)
    {
        for(int i=0;i<tn;i++)
        {
            if(edge[root][i] != Max)
            {
                DFS(i, count);
            }
        }
        int cost = GetCost(root);
        if(cost > td)
        {
            count++;
            for(int i=0;i<tn;i++)
            {
                edge[i][root] = Max;
                edge[root][i] = Max;
            }
        }
    }
};

//你的代码只需要补全上方dTree类来实现算法

//类所需要的其他变量、函数可自己定义编写

//只需要提交这几行代码，其他的都是后台系统自动完成的，类似于 LeetCode，下面为main函数的代码

typedef struct _path
{
    /* data */
    int last;
    int node;
    int adj;
}Path;

int main() 
{
int n, d;               //n为顶点个数，d为路径长度
cin >> n >> d;
dTree dt(n, d);    //构建与初始化树
dt.solution();      //通过solution函数输出结果
return 0;
}

void dTree::solution()
{

    //main函数通过调用dTree类的solution函数，通过cout输出结果。
    int count = 0;
    DFS(0, count);

    cout<<count<<endl;

}