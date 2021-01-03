#include"iostream"
using namespace std;

main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int pd=a[1]-a[0];
    int cur;
    int ans=2;
    int j=2;
    int max=2;
    while(j<n)
    {
        cur=a[j]-a[j-1];//current diff
        if(cur==pd)
        {
            ans++;
        }
        else
        {
            if(ans>max)
                max=ans;
            pd=cur;
            ans=2;
        }
        if(ans>max)
            max=ans;
        
        j++;
    }
    cout<<max<<endl;
}