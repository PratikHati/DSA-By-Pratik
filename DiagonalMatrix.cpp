/*matrix={{3,0,0,0,0},
          {0,6,0,0,0},
          {0,0,2,0,0},
          {0,0,0,8,0},
          {0,0,0,0,4}}
diagonal matrix (m*m)*/
//if (i==j) ,then non zero else 0
#include"iostream"
using namespace std;
struct matrix
{
    int size;
    int A[10];
};
void set(struct matrix *m,int i,int j,int x)//call by address * bcz write operation has to perform
{
    if(i==j)
        m->A[i-1]=x;
    else
        return;//do nothing
}
int get(struct matrix m,int i,int j)//call by name bcz read operation has to perform
{
    if(i==j)
        return m.A[i-1];//return non zero
    return 0;//else return 0
}
void display(struct matrix m)
{
    for(int i=0;i<m.size;i++)
    {
        for(int j=0;j<m.size;j++)
        {
            if(i==j)
                cout<<m.A[i]<<" ";//or can be m.A[j] not j-1 as starting from 0
            else
                cout<<"0 ";
        }
        cout<<endl;//new line
    }
}
main()
{
    struct matrix m;
    m.size=5;
    
    set(&m,1,1,5);
    set(&m,2,2,9);
    set(&m,3,3,4);
    set(&m,4,4,7);
    set(&m,5,5,8);

    display(m);

    cout<<get(m,3,3);
    return 0;
}