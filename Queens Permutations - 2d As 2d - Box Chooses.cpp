#include<iostream>
#include<vector>
using namespace std;

void NQueen(int index, int n, int row, int col, vector<bool> &v, string ans){
    
    if(row == n){
        if(index == n){
            cout<<ans<<endl;
        }
        
        return;
    }
    
    int nrow = 0;
    int ncol = 0;
    string c = " ";
    
    if(col == n-1){         //go to next row
        nrow = row + 1;
        ncol = 0;
        c = "\n";
    }
    else{                   //go to next col
        nrow = row;
        ncol = col + 1;
        c = "\t";
    }
    
    //include i in string
    for(int i=0 ; i<v.size() ;i++){
        
        if(v[i] == false){
            char temp = i+49;
            v[i] = true;
            NQueen(index+1, n ,nrow, ncol, v, ans+'q'+temp+c);
            v[i] = false;
        }
        
    }
    
    //include "" in string
    NQueen(index, n ,nrow, ncol, v, ans+"-"+c);
}
int main(){
    int n;
    cin>>n;
    
    vector<bool> v(n,false);
    
    NQueen(0, n, 0, 0, v, "");
    
    return 0;
}