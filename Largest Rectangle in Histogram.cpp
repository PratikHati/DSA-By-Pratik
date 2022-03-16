class Solution {
public:
    void LeftMostMinimumIndex(vector<int>& left,vector<int>& heights,int n){
        
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            
            
            int index = st.top();;
            
            while(index !=-1 && heights[index] >= heights[i]){
                
                st.pop();
                index = st.top();
            }
            
            left[i] = index;
            st.push(i);
        }
        
    }
    
    void RightMostMinimumIndex(vector<int>& right,vector<int>& heights,int n){
        
        stack<int> st;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--){
            
            int index = st.top();;
            
            while(index !=-1 && heights[index] >= heights[i] ){
                
                st.pop();
                index = st.top();
            }
            
            right[i] = index;
            st.push(i);
            
        }
        
        for(int j=0;j<n;j++){
            if(right[j] == -1){
                right[j] = n;
            }
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        st.push(-1);
        
        int n = heights.size();
        
        vector<int> right(n);
        vector<int> left(n);
        
        vector<int> ans(n);
        int largestarea = INT_MIN;
        
        RightMostMinimumIndex(right, heights, n);
        LeftMostMinimumIndex(left, heights, n);

        
        for(int i=0;i<n;i++){
            
            ans[i] = right[i] - left[i] -1;
            
            int area = ans[i] * heights[i];
            
            largestarea = max(largestarea,area);
        }
        
        return largestarea;
    }
};