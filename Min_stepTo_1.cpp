//o(3^n) Time complexity

#include"iostream"
#include"climits"
using namespace std;
int countMinStepsToOne(int n)
{
    int c1,c2,c3;
    if(n==1)
        return 0;
    c1=countMinStepsToOne(n-1);
    c2=INT_MAX;
    c3=INT_MAX;

    if(n%2==0)
        c2=countMinStepsToOne(n/2);
    if(n%3==0)
        c3=countMinStepsToOne(n/3);

    return 1+min(c1,min(c2,c3));
    
 
}
main()
{
    int n;
    cin>>n;
    cout<<countMinStepsToOne(n);
}