//a array is said to be kth sorted array if any of its element is <=k-1 shifts(either left or right) of its original location
#include<queue>
#include"iostream"
using namespace std;
void ksortarray(int arr[],int size,int k){

    priority_queue<int> pq;//create a priority queueu

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    int j=0;//to keep track of reinsertion into array
    for(int i=k;i<size;i++){
        arr[j]=pq.top();//max in the heap
        pq.pop();//also pop that elemetn
        j++;
        pq.push(arr[i]);
    }

    //also empty pq after use
    for(int i=0;i<k;i++){
        arr[j]=pq.top();
        j++;
        pq.pop();
    }


}

int main(){
    int arr[]={10,12,6,7,9};
    int k=3;
    ksortarray(arr,5,3);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}