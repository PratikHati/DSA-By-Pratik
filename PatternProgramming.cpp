#include"iostream"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=n;
    //bool toggle=false;
    //qn 1// for(int i=0;i<n;i++)
    // {
    //     if(i%2==0)  //even
    //     {
    //         for(int j=0;j<=(i*2);j++)
    //         {
    //             if(j%2==0)
    //             {
    //                 cout<<count<<" ";
    //                 count++;    
    //             }
    //             else
    //                 cout<<"*"<<" ";
                
    //         }
    //     }
    //     else        //odd
    //     {
    //         int tempcount=count+i;
    //         for(int j=i*2;j>=0;j--)
    //         {
    //             if(j%2==0)
    //             {
    //                 cout<<tempcount<<" ";
    //                 tempcount--;
    //                 count++;    
    //             }
    //             else
    //                 cout<<"*"<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
    //qn 2// for(int i=0;i<n;i++)
    // {
    //     if(i%2==0)  //even
    //     {
    //         for(int j=0;j<=n;j++)
    //         {
    //             if(j==n)
    //                 cout<<count_2<<" ";
    //             else
    //                 cout<<count_1<<" ";
    //         }
    //         count_1++;
    //         count_2++;
    //     }
    //     else        //odd
    //     {
    //         for(int j=0;j<=n;j++)
    //         {
    //             if(j==0)
    //                 cout<<count_2<<" ";
    //             else
    //                 cout<<count_1<<" ";
    //         }
    //         count_1++;
    //         count_2++;
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<=2*n;i++)
    {
        if(i<=n)
        {   
            for(int j=0;j<=i;j++)
            {
                cout<<count;
            }
            count++;
        }
        else
        {
            count--;
            for(int j=0;j<=(2*n)-i+1;j++)
            {
                cout<<count;
            }

        }
        cout<<endl;
    }
    return 0;
}
