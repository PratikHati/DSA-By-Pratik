#include"iostream"
#include"queue"
using namespace std;
void printBFS(int **a,int n,int s,bool *v)
{
    queue<int> q;//make a queue
    q.push(s);//push first/root node
    v[s]=true;//,ark it as visited in v[]
    while(!q.empty())
    {
        int temp=q.front();//store front of the queue in a temp variable and pop it also
        q.pop();

        cout<<temp<<" ";//Print temp

        for(int i=0;i<n;i++)//To search all the connected nodes from o to n
        {
            if(a[temp][i]==1 && v[i]==false)//if node==1 and not visited 
            { 
                q.push(i);//Push into queue
                v[i]=true;//mark it as visited
            }
        }
    }
}
main()
{
    int n,e;
    cin>>n>>e;
    int **array=new int*[n];
    for(int i=0;i<n;i++)
    {
        array[i]=new int[n];
        for(int j=0;j<n;j++)
            array[i][j]=0;//initialize with zero
    }

    for(int i=0;i<n;i++)//Take input from the user where the matriz=x is nin zero
    {
        int a,b;
        cin>>a>>b;
        array[a][b]=1;
        array[b][a]=1;
    }

    bool *visited=new bool[n];//Different arrray to keep trak of visited nodes
    for(int i=0;i<n;i++)
    {
        visited[i]=false;//Initialize with false
    }

    printBFS(array,n,0,visited);
}