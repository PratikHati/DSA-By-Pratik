#include"bits\stdc++.h"
using namespace std;
int hexa_dec(string h)
{
    int decimal=0,multiply=1;
    int s=h.size();
    for(int i=s-1;i>=0;i--)
    {
        if(h[i]>='0' && h[i]<='9')
        {
            decimal+=multiply*(h[i]-'0');
        }
        else if(h[i]>='A' && h[i]<='F')
        {
            decimal+=multiply*(h[i]-'A'+10);
        }
        multiply*=16;
    }
    return decimal;
}
main()
{
    string h;
    cin>>h;
    int d=hexa_dec(h);
    cout<<"Decimal is "<<d<<endl;
}
