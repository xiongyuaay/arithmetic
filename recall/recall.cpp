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
    int Data[1000][20];
    vector<set<int>> SiData;
    int num;
public:
    Solution(/* args */);

    void FindMaxNum(vector<int> A, int idx);
    void FindB(vector<int> A);
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
    int Bound(vector<int> A);
};

Solution::Solution()
{
    SiData.resize(20);
    int temp = 0;
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<20;j++)
        {
            cin>>temp;
            if(temp == 1)
            {
                SiData[j].insert(i);
            }
        }
    }
    num = 0;
}

void Solution::FindMaxNum(vector<int> A, int idx)
{
    if(idx == 21)
    {
        A.pop_back();
        FindB(A);
        return;
    }
    for(int i=idx;i<=20;i++)
    {
        A.push_back(i);
        
        if(i < 20 && Bound(A))
        {
            A.pop_back();
            continue;
        }
        
        FindMaxNum(A, i+1);
        A.pop_back();
    }
}

void Solution::FindB(vector<int> A)
{
    if(A.size() == 0)
    {
        return;
    }
    vector<int> B;
    int flag = 0;
    for(int i=0;i<20;i++)
    {
        if(find(A.begin(), A.end(), i) != A.end())
        {
            continue;
        }
        B.push_back(i);
    }
    
    for(auto a:A)
    {
        for(auto d:SiData[a])
        {
            auto it = B.begin();
            while(it != B.end())
            {
                /* code */
                if(SiData[*it].count(d))
                {
                    it = B.erase(it);
                }
                else
                {
                    it++;
                }
            } 
        }
    }
    
    int total = A.size() + B.size();
    if(A.size() >= B.size() && B.size() != 0 && total > num)
    {
        num = total;
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

int Solution::Bound(vector<int> A)
{

    if(A.size() == 0)
    {
        return 0;
    }
    set<int> row;
    set<int> B;
    int flag = 0;
    for(auto a:A)
    {
        for(auto d:SiData[a])
        {
            row.insert(d);
        }
    }
    for(int i=0;i<20;i++)
    {
        if(find(A.begin(), A.end(), i) != A.end())
        {
            continue;
        }
        B.insert(i);
    } 
    for(auto b:B)
    {
        int count1 = 0;
        int count2 = 0;
        for(auto d:SiData[b])
        {
            if(row.count(d))
            {
                count1++;
            }
            if(!row.count(d))
            {
                count2++;
            }
            if(count1 >= 1 && count2 >= 1)
            {
                break;
            }
        }
        if(count1 >= 1 && count2 >= 1)
        {
            B.erase(b);
        }
    }
    
    if(20 - B.size() <= num)
    {
        return 1;
    }
    return 0;
}

int main()
{
    Solution recall;
    int idx = 0;
    vector<int> A;
    recall.FindMaxNum(A, idx);
    cout<<"result"<<endl;
    recall.PrintAB();
    return 0;
}