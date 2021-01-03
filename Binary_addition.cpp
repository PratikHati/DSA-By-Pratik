#include"bits\stdc++.h"
using namespace std;
int reverse(int n)
{
    int rev=0;
    while(n)
    {
        int temp=n%10;
        rev=rev*10+temp;
        n/=10;
    }
    return rev;
}
int binary_addition(int a,int b)
{
    int ans=0;
    int carry=0;
    while(a>0 && b>0)
    {
        if(a%2==0 && b%2==0)
        {
            if(carry==1)
            {
                ans=ans*10+1;
                carry=0;
            }
            else
            {
                ans=ans*10+0;
                carry=0;
                
            }
            
        }
        else if((a%2==0 && b%2==1)||(a%2==1 && b%2==0))
        {
            if(carry==1)
            {
                ans=ans*10+0;
                carry=1;
            }
            else
            {
                ans=ans*10+1;
                carry=0;
            }
        }
        else
        {
            if(carry==1)
            {
                ans=ans*10+1;
                carry=1;

            }
            else
            {
                ans=ans*10+0;
                carry=1;
            }
        }
        a/=10;
        b/=10;
        
    }
    while(a>0)
    {
        if(carry==1)
        {
            if(a%2==1)
            {
                ans=ans*10+0;
                carry=1;
            }
            else
            {
                ans=ans*10+1;
                carry=0;
            }
            
        }
        else
        {
            ans=ans*10+(a%2);
        }
        a/=10;
        
    }
    while(b>0)
    {
        if(carry==1)
        {
            if(b%2==1)
            {
                ans=ans*10+0;
                carry=1;
            }
            else
            {
                ans=ans*10+1;
                carry=0;
            }
            
        }
        else
        {
            ans=ans*10+(b%2);
        }
        b/=10;
    }
    if(carry==1)
        ans=ans*10+1;
    
    ans=reverse(ans);
    return ans;
}
main()
{
    int B1,B2;
    cin>>B1>>B2;
    int B3=binary_addition(B1,B2);
    cout<<B3;
}