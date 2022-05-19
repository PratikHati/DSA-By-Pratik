class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool flag1 = true
        bool flag2 = true;

        int r = matrix.size();
        int c = matrix[0].size();
        
        for(int i=0;i<r;i++){
            if(matrix[i][0] == 0){
                flag2 = false;
            }
        }
        
        for(int i=0;i<c;i++){
            if(matrix[0][i] == 0){
                flag1 = false;
            }
        }
        
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j] == 0){
                    
                    matrix[0 vc
                if(matrix[0][j] == 0 || matrix[i][0] ==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        
        
        if(flag1 == false){
            for(int i=0;i<c;i++){
                matrix[0][i] = 0;
            }
        }
        
        if(flag2 == false){
            for(int i=0;i<r;i++){
                matrix[i][0] = 0;
            }
        }
    }
};