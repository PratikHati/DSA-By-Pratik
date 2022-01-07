#include <bits/stdc++.h>
using namespace std;

int largestForwardDiagonal(const vector<vector<int>> & M){
    int n=M.size();
    int m=M[0].size();
    vector<vector<bool>> B(n,vector<bool>(m));
  
    int maxsum=INT_MIN;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < m; j++)
        {
            int r=i,c=j;
            sum=0;
            while(r<n && c<m && B[r][c]==false){
                sum+=M[r][c];
                B[r][c]=true;
                r++;
                c++;
            }
            maxsum=max(maxsum,sum);
            
        }
    }
    return maxsum;
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>M(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>M[i][j];
        }
    }
    int result = largestForwardDiagonal(M);
    cout<<result;
}


