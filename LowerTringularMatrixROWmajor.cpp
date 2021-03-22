/*matrix={{3,0,0,0,0},
          {4,6,0,0,0},
          {8,2,5,0,0},
          {2,1,7,9,0},
          {1,2,3,5,4}}
Lower Tringular Matrix (m*m) */
//if (j<=i) then non ZERO else 0
//if (i<j) then 0
// zero elements  = n^2-(n(n-1)/2)
//non zero = n(n-1)/2
//total =n*n =n^2

/*---------IMPORTANT FORMULA -------*/
//A[i][j]=(i*(i-1)/2)+(j-1)  for lower tringular row major matrix

#include"iostream"
using namespace std;

struct matrix
{
    int size ;//dimension of array
    int *a ;//array to store non zero
};

void set(struct matrix *m,int i,int j,int d)//* bcz write operation has to perform
{
    if(i>=j)
    {
        int index=(i*(i-1)/2)+j-1;
        m->a[index]=d;//store d in a[(i*(i-1)/2)+(j-1)]
    }
    else
        return; 
}

int get(struct matrix m,int i,int j)
{
    if(i>=j)
    {
        int index=(i*(i-1)/2)+j-1;
        return m.a[index];
    }
    else
        return 0;
}

void display(struct matrix m)
{
    //-------------IMPORTANT------------//
    for(int i=1;i<=m.size;i++)     //as in above formula, we derived it by taking 1 as starting address of array "a"
    {
        for(int j=1;j<=m.size;j++)
        {
            if(i>=j)//non zero
            {
                cout<<get(m,i,j)<<" ";
            }
            else//non zero
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
main()
{
    struct matrix m;
    m.size=5;
    int n=m.size*(m.size-1)/2;
    m.a=new int[n];
    set(&m,1,1,4);
    set(&m,2,2,5);
    set(&m,3,1,2);
    set(&m,3,2,7);
    set(&m,4,3,8);
    set(&m,4,4,9);
    
    display(m);
    return 0;
}