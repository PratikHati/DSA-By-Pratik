/*high-low-high-low-high format*/

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void WAVEsort(int qn[],int size){

    //start from 2nd to size-2
    int start=1;//start from secind position
    while(start<=size-2){//till 2nd last element
        
        if(qn[i]>qn[i-1]){//if middle is larger than previous(left)
            swap(qn[i],qn[i-1]);
        }   

        if(qn[i]>qn[i+1]){//if middle is larger than after(right)
            swap(qn[i],qn[i+1]);
        }

        start+=2;//jump by 2
    }
}
