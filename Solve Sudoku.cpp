#include <bits/stdc++.h>

using namespace std;


bool IsSudoku(vector<vector<int>>& v, int n, int r,int c,int data){

    for(int i=0;i<n;i++){   //curr row
        if(v[r][i] == data){
            return false;
        }
    }

    for(int i=0;i<n;i++){   //curr row
        if(v[i][c] == data){
            return false;
        }
    }

    int x = 3 * (r/3);
    int y = 3 * (c/3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            if(v[x+i][y+j] == data){
                return false;
            }
        }
    }

    return true;
}
void SolveSudoku(vector<vector<int>>& v, int n, int row, int col) {

    if(row == n){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        return;
    }

    int nr,nc;
    if(col == n-1){
        nr = row+1;
        nc = 0;
    }
    else{
        nr = row;
        nc = col+1;
    }

    if(v[row][col] == 0){
        
        for(int i=1;i<=9;i++){

            if(IsSudoku(v,n,row,col,i)){
                
                v[row][col] = i;
                
                SolveSudoku(v,n,nr,nc);
                
                v[row][col] = 0;
            }
        }
    }
    else
        SolveSudoku(v,n,nr,nc);
    return;


}
int main() {
    int n = 9;

    vector<vector<int>> v(9, vector<int>(9, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int data;
            cin >> data;

            v[i][j] = data;
        }
    }

    SolveSudoku(v, n, 0, 0);

    // for (auto x : v) {
    //     for (auto y : x) {

    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
