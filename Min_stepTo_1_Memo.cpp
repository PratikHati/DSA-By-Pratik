#include"iostream"
#include"climits"
using namespace std;
int minstep_Memo(int n,int a[])
{
    if(n<=1)
        return 0;

    if(a[n]!=-1)
        return a[n];

    int x=minstep_Memo(n-1,a);
    int y=INT_MAX;
    int z=INT_MAX;

    if(n%2==0)
        y=minstep_Memo(n/2,a);

    if(n%3==0)
        z=minstep_Memo(n/3,a);


    int ans= 1+min(x,min(y,z));
    a[n]=ans;
    return ans;
}
int countStepsToOne(int n)
{
    int *a=new int[n+1];
    for(int i=0;i<=n;i++)
        a[i]=-1;
    return minstep_Memo(n,a);
}
main()
{
    int n;
    cin>>n;
    cout<<countStepsToOne(n);
}