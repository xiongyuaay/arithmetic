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
};

//你的代码只需要补全上方dTree类来实现算法

//类所需要的其他变量、函数可自己定义编写

//只需要提交这几行代码，其他的都是后台系统自动完成的，类似于 LeetCode，下面为main函数的代码

typedef struct _path
{
    /* data */
    int last;
    int node;
    int cost;
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
    vector<Path> path;
    path.push_back({-1, 0, 0, 0});
    int i;
    while(path.size() != 0)
    {
        Path curr = path.back();
        if(curr.cost > td)
        {
            count++;
            curr.cost = 0;
            curr.adj = 0;
            path.pop_back();
            for(int j=0;j<tn;j++)
            {
                if(edge[curr.node][j] != Max)
                {
                    Path child = {-1, j, 0, 0};
                    path.push_back(child);
                    edge[curr.node][j] = Max;
                }
                
            }
            edge[curr.last][curr.node] = Max;
            continue;
        }
        for(i=curr.adj;i<tn;i++)
        {
            if(edge[curr.node][i] != Max)
            {
                curr.adj = i+1;
                path.pop_back();
                path.push_back(curr);
                Path next = {curr.node, i, curr.cost + edge[curr.node][i], 0};
                path.push_back(next);
                break;
            }        

        }
        if(i >= tn)
        {
            path.pop_back();
        }
        
    }
    cout<<count<<endl;

}