#include"iostream"
using namespace std;
int gcd(int a,int b)
{
    int c;
    while(c=(a%b)!=0)
    {
        a=b;
        b=c;
    }
    return b;
}
main()
{
    int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];

    int n=x[0];
    for(int i=1;i<n;i++)
    {
        n=gcd(n,x[i]);
    }
    cout<<"GCD is "<<n<<endl;
}
