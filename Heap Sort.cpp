void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
        int target = i;
        int child1 = 2*i+1;
        int child2 = 2*i+2;
    
        if(child1< n && arr[child1] > arr[target]){
            target = child1;
        }
    
        if(child2< n && arr[child2] > arr[target]){
            target = child2;
        }
    
        if(target == i){
            return;
        }
    
        swap(arr[i],arr[target]);
        heapify(arr,n,target);
    }

// Main function to do heap sort
    public:
    
    void heapSort(int arr[], int n) {
    // Build max heap

        for(int i=n/2-1;i>=0;i--){
        
            heapify(arr,n,i);
        }
        
        for(int i=0;i<n;i++){
        
            swap(arr[0],arr[n-i-1]);
            heapify(arr,n-i-1,0);
        }
    
        return;
    }