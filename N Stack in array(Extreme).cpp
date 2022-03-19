class NStack
{
public:
    // Initialize your data structure.
    int curr;
    int *ans;
    int *stak;
    int *track;
    NStack(int N, int S)
    {
        // Write your code here.
        ans = new int[N];
        stak = new int[S];
        track = new int[N];
   		
        curr = 0;
        
        for(int i=0;i<S;i++){
            stak[i] = -1;
        }
        
        for(int i=0;i<N;i++){
            track[i] = i+1;
        }
        
        track[N-1] = -1;	//Note
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(curr == -1){
            return false;
        }
        
        int index = curr;
        
        ans[index] = x;
        
        curr = track[index];	//update next free space
        
        
        track[index] = stak[m-1];
        
        stak[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        int index = stak[m-1];
        
        if(index==-1){
            return -1;
        }
        
        stak[m-1] = track[index];
        
		track[index] = curr;
       
        curr = index;
        
        return ans[index];
    }
};