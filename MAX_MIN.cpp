//Find max,min of an array using structure//
#include"iostream"
using namespace std;
struct array
{
    int max;
    int min;
};
struct array find_max_min(int A[],int size)
{
    struct array P;
    if(size==1)//Base case
    {
        P.max=A[0];
        P.min=A[0];
        return P;
    }
    if(A[0]>A[1])
    {
        P.max=A[0];
        P.min=A[1];
    }
    else
    {
        P.max=A[1];
        P.min=A[0];
    }
    for(int i=2;i<size;i++)
    {
        if(A[i]>P.max)
            P.max=A[i];
        else if(A[i]<P.min)
            P.min=A[i];
    }
    return P;
}
main()
{
    int size;
    cin>>size;
    int A[size];
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
    struct array a1=find_max_min(A,size);
    cout<<a1.max<<" "<<a1.min<<endl;
}