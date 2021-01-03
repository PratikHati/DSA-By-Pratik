
#include"bits/stdc++.h"
using namespace std;
int minJumps(int arr[],int n)
{
    int count=0;
    int i=0,j;
    int max;
    while(i<n)
    {
        if(arr[i]==0)//Edge case
            return -1;
        else if(arr[i]>1)
        {
            max=1;
            j=1;
            while((j<=arr[i]) && (i+j<n))
            {
            
                if(arr[i+j]>max)
                    max=arr[i+j];
                j++;
            }
        }
        else
        {
            max=arr[i];
        }
        
        i+=max;
        count++;
    }
    return count;

}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<minJumps(arr,n)<<endl;
    }
}