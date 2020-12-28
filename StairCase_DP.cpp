#include"iostream"
//#include"climits"
using namespace std;
long stair_DP(int n,long a[])
{
    if(n==0)//base case
        return 1;
    if(a[n]!=-1)
        return a[n];
    long x=0,y=0,z=0; 
    if(n-1>=0)
        x=stair_DP(n-1,a);
    if(n-2>=0)
        y=stair_DP(n-2,a);
    if(n-3>=0)
        z=stair_DP(n-3,a);

    long ans=x+y+z;
    a[n]=ans; 
    return ans;
    
}
long staircase(int n)
{
    long *a=new long[n+1];
    for(int i=0;i<=n;i++)
        a[i]=-1;

    return stair_DP(n,a);
}
main()
{
    int n;
    cin>>n;
    cout<<staircase(n);
}