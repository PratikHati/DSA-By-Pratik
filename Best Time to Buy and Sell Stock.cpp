#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int minvalTillNow = INT_MAX;
    int maXDiff = 0;
    
    for(int i=0;i<n;i++){
        if(prices[i] < minvalTillNow){
            minvalTillNow = prices[i];
        }
        int diff = prices[i] - minvalTillNow;
        
        if(diff > maXDiff){
            maXDiff = diff;
        }
    }
    
    return maXDiff;
}