#include"stdio.h"
#include"stdlib.h"
int main()
{
    int n,i,m,k=0,l=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",arr[i]);
        if(arr[i]%2==0)
            m++;
    }
    int b[]=(int )malloc(sizeof(int)*n);
    int c[]=(int )malloc(sizeof(int)*(n-m));
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            b[k++]=arr[i];
        }
        else
        {
            c[l++]=arr[i];
        }
    }
    for(int i=0;i<m;i++)
        printf("%d ",b[i]);
    for(int j=0;j<n-m;j++)
        printf("%d ",c[i]);
    return 0;
}