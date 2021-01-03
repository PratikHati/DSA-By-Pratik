#include"bits\stdc++.h"
using namespace std;
/*int octal_decimal(int o)
{
    int temp=0;
    int multiply=1;
    int  decimal=0;
    while(o)
    {
        temp=o%10;
        decimal=decimal+(temp*multiply);
        multiply*=8;
        o/=10;
    }
    return decimal;
}*/
int decimal_binary(int n)
{
    int x=1;
    int ans=0;
    while(x<=n)
        x*=2;
    x/=2;
    while(x>0)
    {
        int last_digit=n/x;
        n -=last_digit*x;
        x/=2;
        ans=ans*10+last_digit;
       
    }
    return ans;
}
int32_t main()
{
    int d;
    cin>>d;
    //int d=octal_decimal(o);
    int b=decimal_binary(d);
    cout<<"binary is "<<b<<endl;
}