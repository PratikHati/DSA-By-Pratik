#include"bits/stdc++.h"
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void reArrange(int x[],int size)
{
    int j=0;
    for(int i=0;i<size;i++)
    {
        if(x[i]<0)
        {   
            if(i!=j)
                swap(&x[i],&x[j]);
            j++;
        }
        
    }
}
main()
{
    int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    reArrange(x,n);
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
}