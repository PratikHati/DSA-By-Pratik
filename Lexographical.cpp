#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    void myfunc(int n, string s,vector<int> &ans){
        int number = stoi(s);
        
        if(number > n){
            return ;
        }
        
        ans.push_back(number);
        
        string temp = s;
        for(int i=0;i<=9;i++){
            
            char str = i+48;
            temp.push_back(str);
            myfunc(n,temp,ans);
            temp.pop_back();
        }
        return;
    }
    
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        for(int i=1;i<=9;i++){
            string s = to_string(i);
            myfunc(n,s,ans);
        }
        
        return ans;
    }
};