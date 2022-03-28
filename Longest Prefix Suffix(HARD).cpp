#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
    return 0;
}
class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int  n =s.length();
	    
	    int *arr = new int[n];
	    memset(arr,0,sizeof(arr));
	    
	    int i = 0;
	    int j = 1;
	    int curr = 0;
	    while(j<n){
	     
	        if(s[j] == s[i]){
	            
	            i++;
	            arr[j] = i;
	            j++;
	        }
	        else{
	            if(i == 0){
	                arr[j] = 0;
	                j++;
	            }
	            else{
	                i = arr[i-1];
	            }
	            
	        }

	    }
	   
	    return i;
	}
};