#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int fast_index = 0;
    int slow_index = 0;
    
    do{
        fast_index = arr[arr[fast_index]];
        slow_index = arr[slow_index];
    }while(arr[fast_index] != arr[slow_index]);
    
    //will break at common point
    fast_index = 0;
    while(arr[fast_index] != arr[slow_index]){
       fast_index = arr[fast_index];
       slow_index = arr[slow_index];
    }
    
    return arr[slow_index];
}
