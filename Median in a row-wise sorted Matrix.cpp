int median(vector<vector<int>> &matrix, int r, int c){
        // code here    
        //find max and min of entire matrix
        
        int minval = INT_MAX;
        int maxval = INT_MIN;
        
        for(int i=0;i<r;i++){
            
            minval = min(minval,matrix[i][0]);      //leftmost col
            maxval = max(maxval,matrix[i][c-1]);    //rightmost col
        }
        
        int desiredpos = (r*c +1)/2;
        
        
        while(minval < maxval){
            
            int midval = minval+(maxval-minval)/2;  //careful it is not (minval+(maxval-minval))
            
            int count = 0;
            for(int i=0;i<r;++i){
                
                count += upper_bound(matrix[i].begin(),matrix[i].end(), midval) - matrix[i].begin(); // - matrix[i].begin() to get the count
            }
             
            
            if(count < desiredpos){         //critical thinking........ think
                minval = midval+1;
            }
            else{
                maxval = midval;
            }
        }
        
        return minval;
    }