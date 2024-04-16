template<class Type>
class Traveling
{
    friend Type TSP(int**, int [], int, Type);
private:
    /* data */
    void Backtrack(int i);
    int n, 
        *x,
        *bestx;
    Type* *a,
          cc,
          bestc;
};

template<class Type>
void Traveling<Type>::Backtrack(int i)
{
    if(i == n)
    {
        if(a[x[n-1]x[n]] != -1 && a[x[n]x[1]] != -1 && (cc+a[x[n-1]x[n]]+a[x[n]x[1]] < bestc))
        {
            for(int j=1;j<=n;j++)
            {
                bestx[j] = x[j];
            }
        }
    }
    else
    {
        for(int j=i;j<=n;j++)
        {
            if(a[x[i-1]x[j]] != -1 && (cc+a[x[i-1]x[j]] < bestc))
            {
                Swap(x[i], x[j]);
                cc += a[x[i-1]x[i]];
                Backtrack(i+1);
                cc += a[x[i-1]x[i]];
                Swap(x[i], x[j]);
            }
        }
    }
}

template<class Type>
Type TSP(Type **a, int v[], int n)
{
    Traveling<Type> Y;
    Y.x = new int[n+1];
    for(int i=1;i<=n;i++)
    {
        Y.x[i] = i;
    }
    Y.a = a;
    Y.n = n;
    // 遍历每一行，找到最大值并累加
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        int rowMax = Y.a[i][1];
        for (int j = i+1; j <= n; ++j) {
            if (Y.a[i][j] > rowMax) {
                rowMax = Y.a[i][j];
            }
        }
        sum += rowMax; // 累加每行的最大值
    }
    Y.bestc = sum;
    Y.bestx = v;
    Y.cc = 0;
    Y.Backtrack(2);
    delete [] Y.x;
    return Y.bestc;
}