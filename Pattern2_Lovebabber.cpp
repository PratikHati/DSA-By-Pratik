#include<iostream>
using namespace std;
int main(){
    int i=0,j=0;
    while(i<5){
        j=0;
        while(j<=i){            //optimised
            cout<<(i+j+1)<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}