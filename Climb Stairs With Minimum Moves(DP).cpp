#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int cs(int arr[], int n, vector<int>& dp) {
  // write your code here
  int size = n;
  dp[size] = 0;   //already at top stair
  
  for(int i = size-1;i >= 0;i--){

    int range = arr[i];
    int min_right = INT_MAX;

  
    for(int j=1;j<=range;j++){
      if(i+j > n)
        break;

      if(dp[i+j] != -1)
        min_right = min(min_right,dp[i+j]);
    }

    if(min_right == INT_MAX)
      dp[i] = -1;
    else
    {
      dp[i] = min_right+1;
    }
  }

  return dp[0];
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {

    int d;
    cin >> d;
    
    arr[i] = d;

  }

  vector<int> dp(n + 1, INT_MAX);

  cout << cs(arr, n, dp) << endl;
}