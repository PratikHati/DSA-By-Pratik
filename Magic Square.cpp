#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void createMagicMatrix(vector<vector<int>> &ans,int n){
    int i = n/2;
    int j = n-1;

    int number = 1;
    while( number <= (n*n)){
        if(i == -1 && j == n){
            i = 0;
            j = n-2;
        }
        else{
            if(i== -1){
                i = n-1;
            }
            if(j == n){
                j = 0;
            }
        }
        if(ans[i][j] != -1){
            i++;
            j -= 2;
            continue;
        }
        else    
            ans[i][j] = number;
        number++;
        i--;
        j++;
    } 
}
int main()
{
    int n;
    cin>>n;

    vector<vector<int>> ans(n,vector<int>(n,-1));
    createMagicMatrix(ans,n);
    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}