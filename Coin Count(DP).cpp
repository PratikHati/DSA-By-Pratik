#include <iostream>
#include <vector>
using namespace std;

int coinchangecombination(vector<int> coins, int amt, vector<int> dp) {
 
//  write your code here
  //initialization
  dp[0] = 1;  //base case
  //temaining op
  int n = coins.size();
  for(int i=0;i<n;i++){
    int val = coins[i];

    for(int j=val;j<=amt;j++){

      int idx = j - val;

      dp[j] += dp[idx];
    }
  }
  //return last index

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
  cout<<coinchangecombination(coins, amt, dp);

}