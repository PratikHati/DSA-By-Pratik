#include"iostream"
using namespace std;
bool check_sorted(int arr[],int n)
{
    if(n==1 or n==0)
        return true;
    if(arr[0]<arr[1])
        check_sorted(arr+1,n-1);
    else
        return false;
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
    if(check_sorted(arr,n))
        cout<<"sorted"<<endl;
    else
        cout<<"Not sorted"<<endl;
    return 0;
}