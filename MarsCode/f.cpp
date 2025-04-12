#include <iostream>

using namespace std;
int main()
{
    int n = 0;
    cin>>n;


    float total = 2024.0 / n;
    int tol = total;
    if (tol != total)
    {
        tol = total + 1;
    }
    else
    {
        tol = total;
    }
    
    cout<<tol<<endl;
    return 0;
}