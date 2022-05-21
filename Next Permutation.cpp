#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
	if(n==0 || n== 1)
		return permutation;
	int index = -1;
	for(int i=n-2;i>=0;i--){
		if(permutation[i] < permutation[i+1]){
			index = i;
			break;
		}
	}
	if(index != -1){
		int target = permutation[index];//then just find exactly bigger than this
		int nextbiggeridx= -1;
		for(int i=n-1;i>index;i--){
			if(permutation[i] > target){
				nextbiggeridx = i;
				break;
			}
		}
	
		if(nextbiggeridx != -1){
			swap(permutation[index],permutation[nextbiggeridx]);
		}
	}
	
	
	reverse(permutation.begin()+index+1,permutation.end());
	
	return permutation;
}