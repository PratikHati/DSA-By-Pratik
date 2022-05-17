#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(int n,vector<int> val, vector<int> weight,int cap){
    
// write your code here
    vector<int> dp(cap+1,0);

    for(int i=0;i<=cap;i++){

      int sum = i;
      int maxans = INT_MIN;
      for(int j=0;j<n;j++){
        
        int ans = 0;
        if(weight[j] < sum){
          
          int possible_ans1 = dp[i-weight[j]];
          int possible_ans2 = dp[weight[j]];
          ans = possible_ans1 + possible_ans2;
        }
        else if(weight[j] == sum){
          ans = val[j];
        }

        maxans = max(maxans,ans);
        
      }
      dp[i] = maxans;
    }
    
    return dp[cap];
}


int main() {

  int n;
  cin>>n;
  vector<int> val(n);
  for (int i = 0; i < n; i++) {

    cin>>val[i];
  }
  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin>>weight[i];
  }
  int cap;
  cin>>cap;
  
  cout<<unboundedKnapsack(n,val, weight,cap);
  

}