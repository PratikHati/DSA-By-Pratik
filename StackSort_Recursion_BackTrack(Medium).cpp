void myfunc(stack<int> &stack, int x){
    
    if(stack.empty() || stack.top()<x){
        stack.push(x);
        return;
    }
    
    int y = stack.top();
    stack.pop();
    
    myfunc(stack,x);
    stack.push(y);
    return;
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()){
        return ;
    }
    int x = stack.top();
    stack.pop();
    
    sortStack(stack);
    
    myfunc(stack,x);
}