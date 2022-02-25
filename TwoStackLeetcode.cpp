class TwoStack {

public:
	
    int *arr1;
    int *arr2;
    int l1;
    int l2;
    int both;
    int size;
    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        arr1 = new int[s];
        arr2 = new int[s];
        l1=-1;
        l2=-1;
        both=0;
        size=s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(l1 < size-1 && both < size){
            l1++;
            arr1[l1]=num;
            both++;
        }
        else{
            return;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(l2 < size-1 && both < size){
            l2++;
            arr2[l2]=num;
            both++;
        }
        else{
            return;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(l1 >= 0){
            int ans = arr1[l1];
            l1--;
            both--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(l2 >= 0){
            int ans = arr2[l2];
            l2--;
            both--;
            return ans;
        }
        else{
            return -1;
        }
    }

};
