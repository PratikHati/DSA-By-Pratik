class NQueue{
public:
    // Initialize your data structure.
	int *arr;
	int freespot;
	int *front;
	int *rear;
	int *next;
    NQueue(int n, int s){
        // Write your code here.
		arr = new int[s];
		next = new int[s];
		rear = new int[n];
		front = new int[n];
		
		for(int i=0;i<n;i++){
			rear[i] = -1;
			front[i] = -1;
		}
		
		for(int i=0;i<s;i++){
			next[i] = i+1;
		}
		next[s-1] = -1;
		
		freespot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.
		if(freespot == -1){
			return false;
		}
		
		int index = freespot;
		freespot = next[index];
		
		if(front[m-1] == -1){
			front[m-1] = index;
		}
		else{
			int temp = rear[m-1];
			next[temp] = index;	//link it 
		}
		arr[index] = x;
		next[index] = -1;
		rear[m-1] = index;
		
		return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
		int index = front[m-1];
		
		if(index == -1){
			return -1;
		}
		
		int data = arr[index];
		
		front[m-1] = next[index];
		
		next[index] = freespot;
		
		freespot = index;
		
		return data;
    }
};