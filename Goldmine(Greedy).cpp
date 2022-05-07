#include <bits/stdc++.h>

using namespace std;

int GetMax(int r,int c,vector<vector<int>>& arr){

  int pos1 = 0;
  int pos2 = 0;
  int pos3 = 0;

  if(r-1 >= 0){
    pos1 = arr[r][c] + arr[r-1][c+1];
  }

  pos2 = arr[r][c] + arr[r][c+1];

  if(r+1 < arr.size()){
    
    pos3 = arr[r][c] + arr[r+1][c+1];
  }

  return max(pos1, max(pos2,pos3));
}

int collectGold(int r, int c, vector<vector<int>>& arr, vector<vector<int>>& dp) {

    //write your code here
  for(int i = c-2 ; i>=0 ; i--){

    for(int j=r-1 ; j>=0 ; j--){

      arr[j][i] = GetMax(j,i, arr);
    }
  }

  int ans = INT_MIN;
  for(int i=0;i<r;i++){
    ans = max(ans,arr[i][0]);
  }
  
  return ans;
}



int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, 0));

  cout << collectGold(n, m, arr, dp);

}