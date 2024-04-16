template<class Type>
Type  Knapsack(int n, Type b, Type c[], Type a[], Type **p, int x[])
{
    for(int i = 0;i < n;i++)
    {
        遍历重量c[]，使每种物品的数量扩展至[b/a[i]]，并把得到的新的物品总数赋值给原来的n
    }
    int *head = new int[n+2];
    head[n+1] = 0;
    p[0][0] = 0;
    p[0][1] = 0;
    int left = 0, right = 0, next = 1;
    head[n] = 1;
    for(int i = n;j >= 1;i--)
    {
        int k = left;
        for(int j = left;j<=right;j++)
        {
            if(p[j][0]+a[i] > b)break;
            Type y = p[j][0] + a[i], m = p[j][1] + c[i];
            while(k<=right&&p[k][0]<y)
            {
                p[next][0] = p[k][0];
                p[next+1][1] = p[k++][1];
            }
            if(k<=right&&p[k][0]==y)
            {
                if(m<p[k][1])m = p[k][1];
                k++;
            }
            if(m>p[next-1][1])
            {
                p[next][0] = y;
                p[next++][1] = m;
            }
            while(k<=right&&p[k][1]<=p[next-1][1])k++;
        }
        while(k<=right)
        {
            p[next][0] = p[k][0];
            p[next++][1] = p[k++][1];
        }
        left = right+1;right = next-1;head[i-1] = next;
    }
   return p[next-1][1]; 
}