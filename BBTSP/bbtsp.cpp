#include<vector>
#include<algorithm>  

template<class Type>
class Traveling
{
private:
    /* data */
    Type BBTSP(int &bestp);
    int n, 
        *x,
        *bestx;
    Type **a,
         cc,
         bestc;
         NoEdge;
};

template<class Type>
class MinHeapNode
{
    friend Traveling<Type>
private:
    /* data */
    Type lcost,
         cc,
         rcost;
    int s,
        *x;
public:
    operator Type () const {return lcost;}
};

template<class Type>
Type Traveling<Type>::BBTSP(int &bestp)
{
    std::vector<MinHeapNode<Type>> H;
    Type *MinOut = new Type [n+1];
    Type MinSum = 0;
    for(int i=1;i<=n;i++)
    {
        Type Min = NoEdge;
        for(int j=1;j<=n;j++)
        {
            if(a[i][j] != NoEdge && (a[i][j] < Min || Min == NoEdge))
            {
                Min = a[i][j];
            }
        }
        if(Min == NoEdge)
        {
            return NoEdge;
        }
        MinOut[i] = Min;
        MinSum += Min;
    }

    MinHeapNode<Type> E;
    E.x = new int[n];
    for(int i=0;i<n;i++)
    {
        E.x[i] = i+1;
    }
    E.s = 0;
    E.cc = 0;
    E.rcost = MinSum;
    Type bestc = NoEdge;

    while(true)
    {
        if(E.s == n-2)
        {
            if(a[E.x[n-2]][E.x[n-1]] != NoEdge && a[E.x[n-1]][0] != NoEdge && (E.cc+a[E.x[n-2]][E.x[n-1]]+a[E.x[n-1]][E.x[0]] < bestc || bestc != NoEdge))
            {
                bestc = E.cc+a[E.x[n-2]][E.x[n-1]]+a[E.x[n-1]][E.x[0]];
                for(int i=0;i<n;i++)
                {
                    bestp[i] = E.x[i]
                }
            }
            delete [] E;
        }
        else
        {
            for(int i=E.s+1;i<n;i++)
            {
                if(a[E.x[E.s]][E.x[i]] != NoEdge)
                {
                    Type cc = E.cc+a[E.x[E.s]][E.x[i]];
                    Type rcost = E.rcost - MinOut[E.x[E.s]];
                    Type b = cc+rcost;
                    if(b<bestc || bestc ==NoEdge)
                    {
                        MinHeapNode<Type> N;
                        N.x = new int[n];
                        for(int j=0;j<n;j++)
                        {
                            N.x[j] = E.x[j];
                        }
                        N.x[E.s+1] = E.x[i];
                        N.x[i] = E.x[E.s+1];
                        N.cc = cc;
                        N.lcost = b;
                        N.rcost = rcost;
                        H.push_back(N);
                        std::sort(H.begin(), H.end(), [](const MinHeapNode &a, const MinHeapNode &b) 
                        {
                            return a.lcost < b.lcost;
                        });
                    }
                }
            }
        }
        delete [] E;
        if(!H.empty())
        {
            E = H.pop_back();
        }
        if(bestc != NoEdge && E.lcost >= bestc)
        {
            break;
        }
    }
    if(bestc == NoEdge)
    {
        return NoEdge;
    }
    return bestc;
}