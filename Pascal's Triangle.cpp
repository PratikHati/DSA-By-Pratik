#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
	vector<vector<long long int>> v(n,vector<long long int>());
	if(n == 0){
		return v;
	}
	v[0].push_back(1);
	if(n == 1)
		return v;
	v[1].push_back(1);
	v[1].push_back(1);
	if(n == 2){
		return v;
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j == 1){
				v[i-1].push_back(1);
			}
			else{
				if(j == i){
					v[i-1].push_back(1);
				}
				else{
					long long int ans = v[i-2][j-1]+v[i-2][j-2];
					v[i-1].push_back(ans);
				}
			}
		}
	}
	
	return v;
}
