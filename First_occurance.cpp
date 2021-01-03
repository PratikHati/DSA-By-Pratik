#include"iostream"
using namespace std;
/*int first_occurance(int arr[],int n,int x,int i)
{
    if(i==n)
        return -1;
    if(arr[i]==x)
        return i+1;
    else
        first_occurance(arr,n,x,i+1);

}*/
int last_occurance(int arr[],int n,int x,int i)
{
    if(i==n)
        return -1;
    int temp=last_occurance(arr,n,x,i+1);
    if(temp!=-1)//Remp is the real answer
    {
        return tempclear;
    }
    else if(arr[i]==x)
        return i;
    return -1;

}
main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int i=0;
    //cout<<first_occurance(arr,n,x,i)<<endl;
    cout<<last_occurance(arr,n,x,i)<<endl;
}