#include<stack>
int findMinimumCost(string str) {
  // Write your code here
    int length = str.length();
    
    if(length%2 == 1){
        return -1;
    }
    
    stack<char> st;
    for(auto c : str){
        
        if(c == '{'){
            st.push(c);
        }
        else{
            if(!st.empty()){
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
            else{
                st.push(c);
            }
        }
    }
    if(st.empty()){
        return 0;
    }
    
    int size = st.size();
    int a=0,b=0;
    for(int i=0;i<size;i++){
        if(st.top()=='{'){
            a++;
            st.pop();
        }
        else{
            b++;
            st.pop();
        }
    }
    
    return (a+1)/2 + (b+1)/2;
}