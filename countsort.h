void countsort(int qn[],int size){
    //find max
    int m=qn[0];
    for(int i=1;i<size;i++){
        m=max(m,qn[i]);
    }

    //create another array to store repetation 
    int rep[m]={0};//initialize with 0

    //to store repetation of elements in qn[]
    for(int i=0;i<size;i++){
        rep[qn[i]]++;
    }

    //create an answer array
    int ans[size];

    /* important*/
    //opposite traverse qn[]-------------
    for(int i=size-1;i<=0;i--){
        ans[--rep[qn[i]]]=qn[i];//answer array is completed
    }
    //--------------------------------------

    //copy all elemets from qn[] to ans[]
    for(int i=0;i<size;i++){
        qn[i]=ans[i];
    }

    delete []ans;//deallocate ans[]
    delete []rep;//deallocate rep[]
}