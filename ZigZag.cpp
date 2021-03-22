#include"iostream"
#include"cstring"
#include"string.h"
using namespace std;
void convert(string s,int numRows)
{
	if(s.length()==1)
		return ;
		
	char A[numRows][strlen(s)];
	memset(A,0,sizeof(A));	

	for(int i=0;i<numRows;i++)
	{
		for(int j=0;j<strlen(s);j++)
		{
			cout<<A[i][j];
		}
	}
		
		/*
		
		int i=0,j=0,k=0;
		while(k<s.length())
		{
			while(i<numRows)
			{
				A[i][j]=s.charAt(k);
				k++;
				i++;
			}
			i--;
			j++;
			while(i<=0)
			{
				A[i][j]=s.charAt(k);
				k++;
				j++;
				i--;
			}
		}
		
		
		while(i<numRows)
		{
			while(j<s.length())
			{
				if(A[i][j]!=0)
					System.out.println(A[i][j]);
				j++;	
			}
			i++;
		}
		*/
}
main()
{
    string s1;
    cin>>s1;
    int rows;
    cin>>rows;
    convert(s1,rows);

}