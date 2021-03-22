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
//A[i][j]=(i*(i-1)/2)+(j-1)  for row major matrix



#include"iostream"
using namespace std;
struct matrix
{

};
main()
{
    int n;
    cin>>n;
    int size=(n*(n-1))/2;

}