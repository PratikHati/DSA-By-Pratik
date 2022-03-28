#include<iostream>
using namespace std;
int findTheWinner(int n,int k){

    //every itteration/call, we are treeting 0,1,2,3,4,0,1,2    n=5 ,   k=3
    //                                       0,1,x,0,1,2,3,4

    if(n==2){
        if(k%2==0){
            return 0;
        }
        return 1;
    }

    int ans=findTheWinner(n-1,k);

    return (ans+k)%n;       //rememebr answaer is always 0 or 2, nut depending upon n , 
}
int main(){
    
    int n,k;
    cin>>n>>k;

    cout<<findTheWinner(n,k)<<endl;

    return 0;
}