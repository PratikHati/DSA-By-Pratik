#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    int i=0;
    
    while(i<m){
        if(arr1[i] > arr2[0]){
            swap(arr1[i] ,arr2[0]);
            if(n>1 && arr2[0] > arr2[1])
                sort(arr2.begin(),arr2.end());
        }
         i++;
    }
    
    int x = m;
    int y = 0;
    while(x<arr1.size()){
        arr1[x] = arr2[y];
        x++;
        y++;
    }
    
    return arr1;
}