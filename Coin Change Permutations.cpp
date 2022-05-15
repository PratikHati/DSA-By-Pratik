#include <iostream>
#include <vector>
using namespace std;

int coinchangepermutation(vector<int> coins, int amt, vector<int> dp) {

  //  write your code here
  int n = coins.size();
  dp[0] = 1;

  for(int i=1;i<=amt;i++){
    
    for(int j=0;j<n;j++){

      int val = coins[j];
      if(val <= i){

        int idx = i - val;
        dp[i] += dp[idx];
      }
      
    }
  }

  return dp[amt];
}

int main() {
  int n;
  cin >> n;
  vector<int> coins(n, 0);
  for (int i = 0; i < coins.size(); i++) {
    cin >> coins[i];
  }
  int amt;
  cin >> amt;
  vector<int> dp(amt + 1, 0);
  cout<<coinchangepermutation(coins, amt, dp);

}