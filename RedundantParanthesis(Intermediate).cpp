#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    int length = s.length();
    
    for(int i=0;i<length;i++){
        char c = s[i];
        
        if(c=='(' || c=='+' || c=='-' || c =='*' || c=='/'){
            st.push(c);
        }
        else if(c == ')'){
            
            if(st.top() == '(' || st.empty()){
                return true;
            }
            else{
                while(st.top() != '(' && !st.empty()){
                    st.pop();
                }
                if(st.empty()){
                    return true;
                }
                st.pop();
            }
        }
    }
    
    return false;
}
