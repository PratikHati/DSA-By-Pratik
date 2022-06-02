#include<bits/stdc++.h>
bool isSafe(int i,int j,int n,vector<vector<bool>> &b,vector < vector < int >> &arr){
    if(i >=0 && j>=0 && i<n && j<n){
        if(b[i][j] == false && arr[i][j] == 1)
            return true;
    }  
    return false;
}
void findPath(vector < vector < int >> &arr,int n, int i,int j, vector<vector<bool>> b, vector<string> &ans,string str){
    
    if(i==n-1 && j==n-1){
        ans.push_back(str);
        return;
    }
    
    //base case
    
    
    b[i][j] = true;
    
    //do down
    if(isSafe(i+1,j,n,b,arr)){
        findPath(arr,n,i+1,j,b,ans,str+'D');
    }
    
    //do left
    if(isSafe(i,j-1,n,b,arr)){
        findPath(arr,n,i,j-1,b,ans,str+'L');
    }
    
    //do right
    if(isSafe(i,j+1,n,b,arr)){
        findPath(arr,n,i,j+1,b,ans,str+'R');
    }
    
    //do up
    if(isSafe(i-1,j,n,b,arr)){
        findPath(arr,n,i-1,j,b,ans,str+'U');
    }
    
    
    b[i][j] = false;
    return;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    
    vector<string> ans;
    vector<vector<bool>> b(n,vector<bool>(n,false));
    string str = "";
    
    if(arr[0][0] == '0'){
        return ans;
    }
    
    findPath(arr,n,0,0,b,ans,str);
    //sort(ans.begin(),ans.end());
    
    return ans;
}