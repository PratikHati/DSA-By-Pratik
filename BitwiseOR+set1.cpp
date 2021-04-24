//
////TO SET THE GIVEN BIT IS  1
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

    int temp=1<<(p-1);  //LEFT SHIFT 
    n=n|temp;       //bitwise OR
    
    cout<<"bit is set to 1"<<endl;
    cout<<n<<endl;
    return 0;
}