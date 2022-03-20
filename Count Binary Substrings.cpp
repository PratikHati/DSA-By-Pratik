
class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int size = s.length();
        int curr = 1;
        int prev = 0;
        int ans = 0;
        
        for(int i=1;i<size;i++){
            if(s[i] == s[i-1]){
                curr++;
            }
            
            else{
                ans += min(prev,curr);
                prev = curr;
                curr = 1;
            }
        }
        
        return ans+min(prev,curr);   //as last else may be missed
    }
};