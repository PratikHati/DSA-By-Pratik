#include <iostream>
#include <vector>

using namespace std;

int cs(int arr[], int n, vector<int> &dp,int index){
    // write your code here
    if(index > n){
        return 0;
    }
    
    if(dp[index] != -1){
        return dp[index];
    }

    int total_jumps = arr[index];
    int ans = 0;
    
    for(int i=0;i<total_jumps;i++){
        ans += cs(arr,n,dp,index+i+1);
    }

    dp[index] = ans;
    return dp[index];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1,-1);
    //very very important
    dp[n]= 1;   //important
    cout<<cs(arr,n,dp,0)<<endl;
}