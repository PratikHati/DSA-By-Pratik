//Only for 3 rods//
using namespace std;
#include"iostream"
void tower_hanoi(int n,char start,char end,char  medium)
{
    if(n==0)
        return;
    tower_hanoi(n-1,start,medium,end);
    cout<<"Move from "<<start<<" to "<<medium<<endl;
    tower_hanoi(n-1,medium,end,start);
    cout<<"Move from "<<medium<<" to "<<end<<endl;
}
main()
{
    int n;
    cin>>n;
    char a,b,c;
    cin>>a>>b>>c;
    tower_hanoi(n,a,c,b);
}