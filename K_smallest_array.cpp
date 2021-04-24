#include<queue>
#include<iostream>
using namespace std;
int* ksmallest(int arr[],int size,int k){

    priority_queue<int> pq;
    for(int i=0;i<k+1;i++){
        pq.push(arr[i]);//max heap
    }

    for(int i=k+1;i<size;i++){
        pq.pop();//delete max value
        pq.push(arr[i]);//max heap
    }

    pq.pop();//one last time;
    //now smallest k elements are in pq , so pop back to ans[]
    int j=0;
    int *ans=new int[k];//new array of size k
    for(int i=0;i<k;i++){
        ans[j]=pq.top();//store k min element in ans array
        pq.pop();
        j++;
    } 

    return ans;
}
int main()
{
    int arr[]={10,90,35,4,20,5,30,100};
    int k=4;

    int *ans=ksmallest(arr,8,k);
    

    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}