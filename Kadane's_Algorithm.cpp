#include "bits/stdc++.h"
using namespace std;
int maxSubarraySum(int arr[], int n)
{
    
    // Your code here
    sort(arr,arr+n);
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    if(sum>arr[n-1])
        return sum;
    return arr[n-1];

}
int main()
{

    int size;
    cin>>size;
    int x[size];
    for(int i=0;i<size;i++)
        cin>>x[i];
   	cout<< maxSubarraySum(x,size);

}
