class Solution {
public:
    bool IsSudoku(vector<vector<char>> &v,int n, int r,int c, int x){
        
        //check row
        for(int i=0;i<n;i++){
            if(v[r][i] == x+48){
                return false;
            }
        }
        
        //check col
        for(int i=0;i<n;i++){
            if(v[i][c] == x+48){
                return false;
            }
        }
        //check 3x3
        int mr = (r/3)*3;
        int mc = (c/3)*3;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                
                if(v[mr+i][mc+j]==x+48){
                    return false;
                }
            }
        }
        
        return true;
    }
    void solve(vector<vector<char>> &v,int n,int r,int c,vector<vector<char>>& board){
        
        if(r == n){
            
            for(int i=0;i<n;i++){
                
                for(int j=0;j<n;j++){
                    
                    board[i][j] = v[i][j];
                }
            }
            return;
        }
        
        int nr,nc;
        
        if(c == n-1){
            nr = r+1;
            nc = 0;
        }
        else{
            nr = r;
            nc = c+1;
        }
        
        if(v[r][c] == '.'){
            //do
            for(int x=1;x<=n;x++){
                
                if(IsSudoku(v,n,r,c,x)){
                    
                    v[r][c] = x+48 ;
                    
                    solve(v,n,nr,nc,board);
                    
                    v[r][c] = '.' ;
                }
            }
        }
        else{
            solve(v,n,nr,nc,board);
        }
        
        return;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        int n = 9;
        
        vector<vector<char>> c(n,vector<char>(n));
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                c[i][j] = board[i][j];
            }
        }
        
        solve(c,9,0,0,board);
        
        
    }
};