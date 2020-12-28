#include"iostream"
#include"climits"
using namespace std;
int minCount(int n)
{
    if(n==0)
        return ;
    int i=1,a;
    while(i*i<n)
    {
        a=minCount(n-(i*i));
        i++;
    }
    
}
main()
{
    int n;
    cin>>n;
    cout<<minCount(n);
}