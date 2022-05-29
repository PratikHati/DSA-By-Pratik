void heapify(vector<int> &arr, int n,int index){
    
    int child1 = index*2 + 1;
    int child2 = index*2 + 2;
    
    int target = index;
    if(child1 < n && arr[child1] < arr[target]){
        target = child1;
    }
    
    if(child2 < n && arr[child2] < arr[target]){
        target = child2;
    }
    
    if(target == index){
        return;
    }
    
    swap(arr[target],arr[index]);
    heapify(arr,n,target);
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
  
    int first_parent_index =n/2 -1;
   
    
    for(int i=first_parent_index;i>=0;i--){
        heapify(arr,n,i);
    }
    
    return arr;
}
