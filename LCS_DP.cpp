#include"iostream"
#include"cstring"
using namespace std;
int max(int p,int q)//return max
{
    return (p>q)? p:q;
}
int lcs(char x[],char y[],int a,int b)//Time complexity - O()
{
    int matrix[a+1][b+1];//create 2D array to store overlapping subproblems
    int i,j;

    for(i=0;i<a+1;i++)//a+1 because starting address is 0 and we need exactly row =a not a-1 .So an extra row and coloumn req to store 0s- see Applied Gate DSA
    {
        for(j=0;j<b+1;j++)//b+1 bcs we need b rows not b-1 
        {
            if(i==0 || j==0)//for all the elements in  first row and coloumn
            {
                matrix[i][j]=0;//store 0 in first row and first coloumn
            }
            else if(x[i-1]==y[j-1])
            {
                matrix[i][j]=matrix[i-1][j-1]+1;//if same then  1 + matrix[i-1][j-1]
            }
            else
            {
                matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);//if different then max(matrix[i-1][j],matrix[i][j-1]) 
            }
        }
    }
    return matrix[a][b];//return last index

}
/*int lcs(char x[],char y[],int a,int b)//Time complexity - O(2^n)
{
    if(a==0 || b==0)//base case if any of the size is 0
        return 0;
    else if(x[a-1]==y[b-1])//if last index of both array same same
    {
        return 1+lcs(x,y,a-1,b-1);
    }
    else                //if last index if both array different
    {
        return max(lcs(x,y,a-1,b),lcs(x,y,a,b-1));
    }
}*/
main()
{
    //Given input string 
    char x[]="abcdef";
    char y[]="axdvey";

    int a=strlen(x);//string length of a
    int b=strlen(y);//string length of b

    //to find longest common subsequence
    cout<<lcs(x,y,a,b)<<endl;
    return 0;
}