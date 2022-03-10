bool isValidParenthesis(string expression)
{
    // Write your code here.
    int length = expression.length();
    
    stack<char> st;
    
    int index = 0;
    
    while(index < length){
        if(expression[index]=='[' ||expression[index]=='{' ||expression[index]=='(' ){
            char c = expression[index];
            st.push(c);
        }
        else if(expression[index]==']' ||expression[index]=='}' ||expression[index]==')' ){
            
            if(st.empty()){
                return false;
            }
            
            char h = st.top();
            if(expression[index]==']' && h != '['){
                return false;
            }
            
            if(expression[index]=='}' && h != '{'){
                return false;
            }
            if(expression[index]==')' && h != '('){
                return false;
            }
            
            st.pop();
        }
        index++;
    }
    
    if(st.empty()){
        return true;
    }
    
    return false;
}