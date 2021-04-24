#include"iostream"
#include"stdlib.h"
using namespace std;
int findTotalSum(int s,int a[],int p)
{
    int dif=0,sum=0;   
    for(int i=p;i<s;i++)
    {
        dif=abs(a[i]-a[i-1]);
        sum+=dif;
    }
    return sum;
}
main()
{
    int size;
    cin>>size;  //take input size

    int array[size];
    for(int i=0;i<size;i++)
        cin>>array[i];

    int pos;
    cin>>pos;   //take position    
    cout<<findTotalSum(size,array,pos)<<endl;
}