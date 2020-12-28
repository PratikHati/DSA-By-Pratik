#include"iostream"
using namespace std;

//TOP-DOWN APPROACH//
//Recursion approach//

int fibonacci(int n,int ans[])
{
	if(n<=1)//Base+Edge
		return n;
	
	if(ans[n]!=-1)//Check whether the ans is presnt in array or not
		return ans[n];
		
	int a=fibonacci(n-1,ans);
	int b=fibonacci(n-2,ans);
	
	ans[n]=a+b;//Store it in answer array
	
	return ans[n];//return the answer
}
int fibo_DP(int n)
{
	int *array=new int[n+1];//Dynamically create an array of n+1 size(to store results of each recursion call)
	for(int i=0;i<=n;i++)//Initialize the entire array with -1(as -1 is not the fibo of any number)
		array[i]=-1;
	return fibonacci(n,array);
}
main()
{
	int n;
	cout<<"Enter the Fibonacci number"<<endl;
	cin>>n;
	cout<<fibo_DP(n);
}
