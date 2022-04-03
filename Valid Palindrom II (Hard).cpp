class Solution {
public:
    bool normalpalindrom(string s){
        int size = s.length();
        
        int i=0;
        int j=size-1;
        
        while(i<j){
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    bool validPalindrome(string s) {
        
        int size = s.length();
        
        int i=0;
        int j=size-1;
        
        while(i<j){
            if(s[i] != s[j]){
                if(i == j-1){
                    return  true;
                }
                
                //delete left
                string temp1 = s.substr(i,j-i);
                bool ans1 = normalpalindrom(temp1);
                 
                //delete right
                string temp2 = s.substr(i+1,j-i);
                bool ans2 = normalpalindrom(temp2);
                
                return ans1 || ans2;
            }
            i++;
            j--;
        }
        
        return true;
    }
};