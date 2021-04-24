//
////TO SET THE GIVEN BIT IS 0 
//

#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;
    int p;
    cout<<"Enter position whose bit has to set 1"<<endl;
    cin>>p;

    int mask=~(1<<(p-1));//"~" 1's complement ,"<<" left shifting
    n=(n&mask);       //masking i.e. making that particular bit "0"
    
    
    cout<<"bit is set to 0"<<endl;
    cout<<n<<endl;
    return 0;
}