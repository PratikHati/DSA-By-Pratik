#include"bits\stdc++.h"
using namespace std;
class Solution
{   
    public:
        int getMinDiff(int arr[], int n, int k) 
        {
            if(n==1)
                return 0;
            sort(arr,arr+n);
            
            int ans=arr[n-1]-arr[0];
            
            int big=arr[n-1]-k;
            int small=arr[0]+k;
            
            if(big<small)
                swap(big,small);
            
            for(int i=1;i<n-1;i++)
            {
                int add=arr[i]+k;
                int sub=arr[i]-k;
                
                if(sub>=small or add<=big)
                    continue;
                if(big-sub<=add-small)
                    small=sub;
                else
                    big=add;
            }    
            return min(big-small, ans);
            
        }
};
main()
{
	int k,n;
	cin>>k>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	Solution obj;
	int ans=obj.getMinDiff(a,n,k);
	cout<<ans<<endl;
	return 0;
}
