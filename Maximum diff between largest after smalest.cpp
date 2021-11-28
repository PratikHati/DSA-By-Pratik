#include<iostream>
using namespace std;

int findMaxDiff(int arr[],int n){

    int ans=0;
    for(int i=1;i<n;i++){

        for(int j=0;j<i;j++){

            if(arr[j]<arr[i]){
                int diff=arr[i]-arr[j];
                ans=min(ans,diff);
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter arr"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<findMaxDiff(arr,n)<<endl;
}