#include<iostream>
#include<cstring>
using namespace std;

void solve(int arr[2001][1001]) {
  
  int m = 1e9+7;
  
  for(int i=1; i<=2000; ++i){
    for(int j=0; j<=1000; ++j){
      
      if(j==0 || i==j){
        arr[i][j]=1;
      }
      else if(i > j){
        arr[i][j] = (arr[i-1][j-1] + arr[i-1][j])%m; 
      }
    }
  }
  
  return;
}
int main(){
    int t;
    cin>>t;
    
    auto arr = new int[2001][1001];
    memset(arr, 0, sizeof(arr));
    solve(arr);

    while(t--){
        int n,k;
        cin>>n>>k;

        cout<<arr[n+k-1][n-1]<<endl;
    }

    return 0;
}