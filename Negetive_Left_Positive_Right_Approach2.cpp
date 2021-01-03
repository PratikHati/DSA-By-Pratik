#include"bits/stdc++.h"
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void reArrange(int x[],int l,int r)
{
    while(l<=r)
    {
        if(x[l]<0 && x[r]>0)
        {
            l++;
            r--;
        }
        else if(x[l]<0 && x[r]<0)
        {
            l++;
        }
        else if(x[l]>0 && x[r]>0)
        {
            r--;
        }
        else
        {
            swap(&x[l],&x[r]);
            l++;
            r--;
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
    reArrange(x,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
}