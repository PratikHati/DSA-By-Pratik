#include"iostream"
using namespace std;

//BOTTOM-UP APPROACH//
//Iterative approach//

int fibo_DP(int n)
{
	int *array=new int[n+1];
	array[0]=0;
	array[1]=1;

	for(int i=2;i<=n;i++)
	{
		array[i]=array[i-1]+array[i-2];
	}
	return array[n];
}
main()
{
	int n;
	cin>>n;
	cout<<fibo_DP(n);
}