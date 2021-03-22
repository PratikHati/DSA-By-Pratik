#include"iostream"
using namespace std;
int fibo(int n)
{
    if(n==1 or n==0)//base case
        return n;
    else
    {
        int arr[n]={0};//initialize with 0
        arr[0]=0;       
        arr[1]=1;

        for(int i=2;i<=n;i++)//main loop
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        
        return arr[n];
    }
}
main()
{
    cout<<fibo(10)<<endl;
    return 0;
}