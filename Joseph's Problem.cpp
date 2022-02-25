#include<iostream>
using namespace std;
int findTheWinner(int n,int k){

    if(n==2){
        if(k%2==0){
            return 0;
        }
        return 1;
    }

    int ans=findTheWinner(n-1,k);

    return (ans+k)%n;
}
int main(){
    
    int n,k;
    cin>>n>>k;

    cout<<findTheWinner(n,k)<<endl;

    return 0;
}