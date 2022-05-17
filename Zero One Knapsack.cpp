#include <iostream>
#include <vector>

using namespace std;

int zeroOneKnapsack(int n,vector<int> val, vector<int> weight,int cap){
 
//  write your code here
  vector<vector<int>> dp(n+1, vector<int>(cap+1));

  for(int i=0;i<=n;i++){
    for(int j=0;j<=cap;j++){    //j as cap
      if(i==0 || j==0){
        dp[i][j] = 0;
      }
      else{
        if(weight[i-1] <= j){
          //include
          //not include
          dp[i][j] = max(dp[i-1][j] , dp[i-1][j-weight[i-1]]+val[i-1]);
        }
        else{
          //not include
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }

  return dp[n][cap];
}

int main() {
    
  int n;
  cin >> n;
  
  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  
  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }
  
  int cap;
  cin >> cap;
  
  cout<<zeroOneKnapsack(n,val,weight,cap);


}