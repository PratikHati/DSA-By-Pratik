//
////TO KNOW THE GIVEN BIT IS 0 OR 1
//
#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;
    int p;
    cout<<"Enter position"<<endl;
    cin>>p;
    //Explanition------------------
    //n=6 that is n=0110
    //temp= pow(2,p-1) , let p=3
    //thus temp=0100
    //0110 & 0100 = 0100 i.e >0

    //int temp=pow(2,p-1) or int temp=1<<p; both same
    
    int temp=1<<(p-1);      //left shift i.e multiply with 2^p
    //p-1 as if p=0 i.e 2^0 
    if((temp&n)>0)      //bitwise "&"
        cout<<"bit is 1"<<endl;
    else
        cout<<"bit is 0"<<endl;
    

    return 0;
}