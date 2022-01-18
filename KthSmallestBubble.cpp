#include<iostream>
using namespace std;
void swap(int* a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int kthSmallest(int arr[], int l, int r, int k){
        int count=0;
        while(count<k){
            
            for(int i=r;i>=l+1+count;i--){
                if(arr[i-1]>arr[i]){
                    swap(&arr[i],&arr[i-1]);
                }
            }
            
            count++;
        }
        return arr[k-1];
}
int main(){
    int arr[]={7, 10, 4 ,3 ,20, 15};
    cout<<kthSmallest(arr,0,5,3);
}