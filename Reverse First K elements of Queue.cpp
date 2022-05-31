queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    int n = q.size();
    stack<int> st;
    int i=0;
    while(i<k){
        st.push(q.front());
        q.pop();
        i++;
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    i = 0;
    while(i < n-k){
        q.push(q.front());
        q.pop();
        i++;
    }
    
    return q;
}