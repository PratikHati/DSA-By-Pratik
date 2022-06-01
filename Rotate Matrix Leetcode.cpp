class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<row;i++){
            int k=col-1;
            for(int j=0;j<col/2;j++){
                swap(matrix[i][j],matrix[i][k]);
                k--;
            }
        }
        
    }
};