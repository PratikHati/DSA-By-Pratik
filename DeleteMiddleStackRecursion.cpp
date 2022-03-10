void myfunc(stack<int>&inputStack, int start,int end){
    
    if(start == end/2){
        inputStack.pop();
        return;
    }
   
    int current = inputStack.top();
    inputStack.pop();
    myfunc(inputStack,start+1,end);
    inputStack.push(current);
    return;
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
    myfunc(inputStack,0,N);
   
}