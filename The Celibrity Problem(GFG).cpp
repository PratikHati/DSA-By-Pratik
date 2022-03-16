
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()!=1){
            
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(M[a][b] == 0){
                
                if(M[b][a] == 1){
                    st.push(a);
                }
            }
            if(M[b][a] ==0){
                
                if(M[a][b] == 1){
                    st.push(b);
                }
            }
            
            if(st.empty()){
                return -1;
            }
        }
        
        int ans = st.top();
        for(int j=0;j<n;j++){
            if(M[ans][j] == 1){
                return -1;
            }
        }
        
        for(int j=0;j<n;j++){
            if(M[j][ans] == 0 && j != ans){
                return -1;
            }
        }
        
        return ans;
    }
};