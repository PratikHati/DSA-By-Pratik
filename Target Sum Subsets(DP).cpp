#include <bits/stdc++.h>
using namespace std;
void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
void targetSumPair(vector<int> &arr, int target,vector<vector<bool>> &dp)
{
    //write your code here
    //initialization
    int n = arr.size();
    for(int i=0;i<=target;i++){
        if(i != 0){
            dp[0][i] = false;
        }
        else{
            dp[0][i] = true;
        }
    }

    for(int i=1;i<=n;i++){
        dp[i][0] = true;
    }

    //do rest operation by tracking arr[]

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            
            int val = arr[i-1];

            if(val < j){

                dp[i][j] = dp[i-1][j] || dp[i-1][j-val] ;
            }else{

                if(val == j){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    if(dp[n][target]){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> vec(n, 0);
    input(vec);
    cin >> target;

    vector<vector<bool>> dp(n+1, vector<bool>(target+1,false));
    targetSumPair(vec, target,dp);
    return 0;
}