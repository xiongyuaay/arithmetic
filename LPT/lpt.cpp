#include <iostream>
#include <vector>
#include <algorithm>

typedef struct _work
{
    /* data */
    int serial;
    int time;
}Work;

class LPT
{
private:
    /* data */
    int n;
    int m;
    std::vector<Work> sequence;
    std::vector<int> state;
public:
    LPT(int _n, int _m);
    int solution();
};

LPT::LPT(int _n, int _m)
{
    n=_n;
    m=_m;
    state.resize(_m, 0);
    sequence.resize(_n);
    int count = 0;
    for(auto &it:sequence)
    {
        it.serial = count;
        count++;
        std::cin>>it.time;
    }
}

int LPT::solution()
{
    std::sort(sequence.begin(), sequence.end(), [](Work a, Work b){return a.time < b.time;});
    for(int i=0;i<n;i++)
    {
        Work j=sequence.back();
        sequence.pop_back();
        *state.begin() += j.time;
        std::sort(state.begin(),state.end());
    }

    return *(state.end()-1);
}

int main()
{
    int n,m;
    std::cin>>n>>m;
    LPT solu(n, m);
    std::cout<<solu.solution()<<std::endl;
}