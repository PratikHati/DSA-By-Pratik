//only applicable to array of element having 0,1,2
void DNFsort(int qn[],int size){//O(n)
    
    int low=0;//pointer to lower address
    int mid=0;//initially both at starting loaction
    int high=size-1;//initialized at last location

    while(mid<=high){
        
        if(qn[mid]==0){//swap (low ,mid), low++,mid++
            swap(qn[mid],qn[low]);
            mid++;
            low++;
        }

        else if(qn[mid]==1){//mid++
            mid++;
        }

        else{//if(mid==2) swap(mid,high),high--
            swap(qn[mid],qn[high]);
            high--;
        }
    }
}