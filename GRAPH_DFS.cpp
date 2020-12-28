#include"iostream"
using namespace std;
void print(int **a,int n,int s,bool *v)
{
    cout<<s<<" ";
    v[s]=true;

    for(int i=0;i<n;i++)
    {
        if(i==s)
            continue;   
        if(a[s][i]==1)
        {
            if(v[i]==true)
                continue;
            print(a,n,i,v);
        }
            
    }
}
main()
{
    int n,e;//nodes and edges
    cin>>n>>e;

    int **array=new int*[n];//Dynamic 2D array 

    for(int i=0;i<n;i++)
    {
        array[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            array[i][j]=0;//initialize with 0
        }

    }

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        array[a][b]=1;
        array[b][a]=1;
    }

    bool *visited=new bool[n];

    for(int i=0;i<n;i++)
        visited[i]=false;

    print(array,n,0,visited);
}