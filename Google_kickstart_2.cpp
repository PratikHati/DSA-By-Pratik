#include"iostream"
using namespace std;
int record_breaking(int x[],int n)
{
    int max=x[0];
    int ans=0;
    for(int i=1;i<n;i++)
    {   
        if(x[i]>max && x[i]>x[i+1])
        {
            max=x[i];
            i++;
            ans++;
        }
    }
    return ans;
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }
        x[n]=-1;
        cout<<"Answer is "<<record_breaking(x,n+1)<<endl;
    }
    return 0;
}