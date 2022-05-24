class Solution {
public:
    bool isFeasible(int r,int c,int n){
        if(r>=0 && r<n && c>=0 && c<n){
            return true;
        }
        return false;
    }
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<double>> prev(n,vector<double>(n,0.0));
        vector<vector<double>> curr(n,vector<double>(n,0.0));

        
        double ans = 0.0;
        if(k==0){
            return 1.0;
        }
        
        int dx[] = {-2,-1,1,2,-2,-1,1,2};
        int dy[] = {-1,-2,-2,-1,1,2,2,1};
        prev[row][column] = 1.0;
        
        
        for(int i=1;i<=k;i++){
            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    
                    if(prev[x][y] != 0){
                        for(int z=0;z<8;z++){
                            int p = x+dx[z];
                            int q = y+dy[z];
                            
                            if(isFeasible(p,q,n)){
                                curr[p][q] += (prev[x][y]/8.0);
                            }
                        }
                    }
                }
                
            }
            for (int m = 0; m < n; m++) {
                for (int p = 0; p < n; p++) {
                    prev[m][p] = curr[m][p];
                    curr[m][p] = 0;
                }
            }
                
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans += prev[i][j];
            }
        }
        
        return ans;
    }
};