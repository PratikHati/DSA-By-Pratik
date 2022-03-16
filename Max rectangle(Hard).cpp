class Solution{
  public:
    void fillleft(vector<int> &left,int M[MAX][MAX], int row, int n, int m){
        
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<m;i++){
            
            int index = st.top();
            
            while(index!=-1 && M[row][index] >= M[row][i]){
                st.pop();
                
                index = st.top();
            }
            
            
            left[i] = index;
            
            st.push(i);
        }
    }
    
    void fillright(vector<int> &right,int M[MAX][MAX], int row, int n, int m){
        
        stack<int> st;
        st.push(-1);
        
        for(int i=m-1;i>=0;i--){
            
            int index = st.top();
            
            while(index!=-1 && M[row][index] >= M[row][i]){
                st.pop();
                
                index = st.top();
            }
        
            
            right[i] = index;
            
            st.push(i);
        }
        
        for(int j=0;j<m;j++){
            
            if(right[j] == -1){
                right[j] = m;
            }
        }
    }
    
    int largestArea(int M[MAX][MAX], int row, int n, int m){
        
        stack<int> st;
        vector<int> right(m);
        vector<int> left(m);
        
        fillleft(left, M, row,n, m);
        fillright(right, M, row, n, m);
        
        int max_area = INT_MIN;
        
        for(int i=0;i<m;i++){
            
            int diff = right[i] - left[i] -1;
            
            int area = diff * M[row][i];
            
            max_area = max(max_area, area);
        }
        
        return max_area;
        
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans = -1;
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(M[i][j] !=0)
                    M[i][j] = M[i-1][j] +M[i][j];
                else
                    M[i][j] = 0;
            }
        }
        
        for(int k=0;k<n;k++){
            
            int max_area = largestArea(M,k,n,m);
            
            ans = max(ans,max_area);
        }
        
        return ans;
    }
};
