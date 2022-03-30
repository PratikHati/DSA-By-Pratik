class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(front ==0  && rear == size-1){
            return false;
        }
        
        if(front != 0 && rear == (front-1) % (size-1)){
            return false;
        }
        
        if(front == -1){
       		front = rear = 0;
            arr[front] = x;
            return true;
        }
        if(front == 0 && rear != size-1){
            front = size-1;
            arr[front] = x;
            return true;
        }
        else{
            front--;
            arr[front] = x;
            return true;
        }
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(front ==0  && rear == size-1){
            return false;
        }
        
        if(front != 0 && rear == (front-1) % (size-1)){
            return false;
        }
        
        if(front == -1){
       		front = rear = 0;
            arr[rear] = x;
            return true;
        }
        if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = x;
            return true;
        }
        else{
            rear++;
            arr[rear] = x;
            return true;
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(front == -1){
            return -1;
        }
        if(front == rear){
            int d = arr[front];
            front = rear = -1;
            return d;
        }
        if(front == size-1){
            int d = arr[front];
        	front=0;
            return d;
        }
        else{
             int d = arr[front];
        	front++;
            return d;
        }
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(rear == -1){
            return -1;
        }
        if(front == rear){
            int d = arr[rear];
            front = rear = -1;
            return d;
        }
        if(rear == 0){
            int d = arr[rear];
        	rear=size-1;
            return d;
        }
        else{
         	int d = arr[rear];
        	rear--;
            return d;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(front == -1){
            return -1;
        }
        int d = arr[front];
       	return d;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(front == -1){
            return -1;
        }
        int d = arr[rear];
       	return d;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1){
            return true;
        }
        
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        
        if(front ==0  && rear == size-1){
            return true;
        }
        
        if(front!= 0 && rear == (front-1) % (size-1)){
            return true;
        }
        
        return false;
    }
};