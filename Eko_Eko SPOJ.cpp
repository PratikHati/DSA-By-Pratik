#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
bool isCutPossible(vector<int> arr,int m,int mid){
    long long sum=0;
    int size=arr.size();
    for(int i=0;i<size;i++){
        if(arr.at(i)>=mid){
            sum+=arr.at(i)-mid;
        }
        if(sum>=m){
            return true;
        }
    }
    if(sum>=m){
        return true;
    }
    return false;
}
long long EkoEko(vector<int> arr,int m){x
    long long start=0;
    long long end=0;
    int size=arr.size();
    for(int i=0;i<size;i++){
        end=max(end,arr.at(i));
    }
    long long mid=start+(end-start)/2;
    long long ans=0;
    while(start<=end){
        if(isCutPossible(arr,m,mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> qn;
    for(int i=0;i<n;i++){
        int ans=0;
        cin>>ans;
        qn.push_back(ans);
    }
    cout<<EkoEko(qn,m);
    return 0;
}