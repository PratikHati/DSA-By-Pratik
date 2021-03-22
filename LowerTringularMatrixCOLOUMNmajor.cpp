/*matrix={{3,0,0,0,0},
          {4,6,0,0,0},
          {8,2,5,0,0},
          {2,1,7,9,0},
          {1,2,3,5,4}}
Lower Tringular Matrix (m*m) */
//if (j<=i) then non ZERO else 0
//if (i<j) then 0
//non zero elements  = n^2-(n(n-1)/2)


/*---------IMPORTANT FORMULA -------*/
//A[i][j]=[{n(j-1)}-{(j-2)*(j-1)/2}]+(i-j)  for coloumn major matrix

#include"iostream"
#include"stdlib.h"

using namespace std;
struct matrix
{
    int size;
    int *a;//array to store non zero elements
};

void set(struct matrix *m,int i,int j,int d)
{
    if(i>=j)
    {
        int index=((m->size)*(j-1))+((j-2)*(j-1)/2)+(i-j);
        m->a[index]=d;
    }
    else
        return;
}

int get(struct matrix m,int i,int j)
{
    if(i>=j)
    {
        int index=(m.size)*(j-1)+(((j-2)*(j-1))/2)+(i-j);
        return m.a[index];
    }
    else
    {
        return 0;
    }
}

void display(struct matrix m)
{
    //-------------IMPORTANT------------//
    for(int i=1;i<=m.size;i++)     //as in above formula, we derived it by taking 1 as starting address of array "a"
    {
        for(int j=1;j<=m.size;j++)
        {
            cout<<get(m,i,j)<<" ";
        }
        cout<<endl;
    }
}

main()
{
    struct matrix m;
    int x;
    cin>>x;
    m.size=x;
    m.a=new int[x*(x-1)/2];
    if(!m.a)
    {
        cout<<"Memory error"<<endl;
        exit(0);
    }

    set(&m,1,1,1);
    set(&m,2,1,2);
    set(&m,2,2,3);
    set(&m,3,1,5);
    set(&m,3,2,5);
    set(&m,3,3,7);
    set(&m,4,1,8);
    set(&m,4,2,4);
    set(&m,4,3,9);
    set(&m,4,4,7);

    display(m);
    return 0;
}