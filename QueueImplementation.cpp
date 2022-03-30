class Queue {
    int *arr;
    int frnt;
    int rear;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size = 10001;
        arr = new int[size];
        rear = 0;
        frnt = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frnt==rear){
            frnt = 0;
            rear = 0;
            return true;
        }
        return false;
    }
    

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear+1 == size){
            return;
        }
       
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
            return -1;
        }
        
        int d = arr[frnt];
        frnt++;
        return d;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()){
            return -1;
        }
        
        int d = arr[frnt];
        return d;
    }
};