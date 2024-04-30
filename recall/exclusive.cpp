#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution
{
private:
    /* data */
    vector<int> bestA;
    vector<int> bestB;
    vector<set<int>> Data;
    int meclu[20][20];
    set<int> A;
    set<int> B;
    int num;
    int delta;
public:
    Solution();
    void BackTrack(int idx);
    void Store();
    int Bound();
    void check()
    {
        for(auto b:B)
        {
            if(A.count(b))
            {
                A.erase(b);
            }
        }
    }
    void PrintAB()
    {
        auto a = bestA.begin();
        while(a != bestA.end())
        {
            if(a + 1 == bestA.end())
            {
                cout<<*a<<endl;
                break;
            }
            cout<<*a<<' ';
            a++;
        }

        auto b = bestB.begin();
        while(b != bestB.end())
        {
            if(b + 1 == bestB.end())
            {
                cout<<*b<<endl;
                break;
            }
            cout<<*b<<' ';
            b++;
        }
    }
};

Solution::Solution()
{
    Data.resize(20);
    int temp = 0;
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<20;j++)
        {
            cin>>temp;
            if(temp == 1)
            {
                Data[j].insert(i);
            }
        }
    }
    num = 0;
    delta = 20;

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            int flag = 0;
            for(auto d:Data[j])
            {
                if(Data[i].count(d))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                meclu[i][j] = 1;
            }
            else
            {
                meclu[i][j] = 0;
            }
        }
    }
}

int main()
{
    Solution recall;
    int idx = 0;
    vector<int> A;
    recall.BackTrack(idx);
    cout<<"result"<<endl;
    recall.PrintAB();
    return 0;
}

void Solution::BackTrack(int idx)
{
    if(idx == 21)
    {
        A.erase(20);
        Store();
        return;
    }
    for(int i=idx;i<=20;i++)
    {
        A.insert(i);
        
        if(i < 20 && Bound())
        {
            A.erase(i);
            continue;
        }
        
        BackTrack(i+1);
        A.erase(i);
    }
}

void Solution::Store()
{
    B.clear();
    int flag = 0;
    for(int i=0;i<20;i++)
    {
        flag = 0;
        for(auto a:A)
        {
            if(meclu[i][a] == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            B.insert(i);
        }
    }
    check();
    int total = A.size() + B.size();
    int sub = A.size() - B.size();
    if(A.size() >= B.size() && B.size() != 0 && A.size() != 0 && (total > num || (total == num && sub < delta)))
    {
        num = total;
        delta = sub;
        bestA.clear();
        bestB.clear();
        for(auto it:A)
        {
            bestA.push_back(it);
        }
        for(auto it:B)
        {
            bestB.push_back(it);
        }
    }
}

int Solution::Bound()
{
    return 0;
}
