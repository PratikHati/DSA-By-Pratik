void heapSort(int arr[], int n) {//space complexity=O(1)
    // Write your code
    //insert in minheap order
	int child,parent;
    for(int i=1;i<n;i++){//min heaped array
        
        child=i;
        while(child>0){
    		parent=(child-1)/2;
        
      	  	if(arr[child]<arr[parent]){//swap
            	int temp=arr[child];
            	arr[child]=arr[parent];
            	arr[parent]=temp;
        	}
            else
                break;
            child=parent;
        }
    }
    
    //now sort that heaped array
    int size=n;
    while(size>1){
        int temp=arr[0];
        //swap
        arr[0]=arr[size-1];
        arr[size-1]=temp;//don't touch this
        size--;
    
    	parent=0;
        int lchild=(2*parent)+1;
        int rchild=(2*parent)+2;
        
        while(lchild<size){
            
            int temp=parent;
            if(arr[lchild]<arr[temp]){
				temp=lchild;
            }
            
            if(arr[rchild]<arr[temp] && rchild<size){
                temp=rchild;
            }
            
            if(temp==parent){
                break;
            }
            
            //else swap
            int swap=arr[temp];
            arr[temp]=arr[parent];
            arr[parent]=swap;
            
            //mobe pointer to next parent and child
            parent=temp;
            lchild=(2*parent)+1;
            rchild=(2*parent)+2;
        }
        
		
    }
    
}