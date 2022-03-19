#include<stack>
#include<iostream>
using namespace std;
class SpecialStack {
    // Define the data members.
	int mini;
    stack<pair<int,int>> st;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    SpecialStack(){
        
        mini = INT_MAX;
    }
    void push(int data) {
        // Implement the push() function.
        mini = min(mini,data);
        
        pair<int,int> p;
        p.first = data;
        p.second = mini;
        
        st.push(p);
    }

    int pop() {
        // Implement the pop() function.
        if(st.empty()){
            return -1;
        }
        pair<int,int> p = st.top();
        
        st.pop();
        
        pair<int,int> p2 = st.top();
        
        //VERY VERY IMPORTANT
        mini = p2.second;	//corner case
        
        return p.first;
    }

    int top() {
        // Implement the top() function.
        if(st.empty()){
            return -1;
        }
        pair<int,int> p = st.top();
        
        return p.first;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(st.empty()){
            return true;
        }
        return false;
    }

    int getMin() {
        // Implement the getMin() function.
        if(st.empty()){
            return -1;
        }
        pair<int,int> p = st.top();
        
        return p.second;
    }  
};