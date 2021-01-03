#include <iostream>
using namespace std;
void rotate(int x[],int n)
{
	int temp=x[n-1];
	for(int i=n-1;i>0;i--)
	{
		x[i]=x[i-1];
	}
	x[0]=temp;
}
int main() 
{
	//code
	int T;
	cin>>T;
	while(T)
	{
	    int n;
	    cin>>n;
	    int x[n];
	    for(int i=0;i<n;i++)
	        cin>>x[i];
        rotate(x,n);
		for(int i=0;i<n;i++)
	        cout<<x[i]<<" ";
	}
	return 0;
}