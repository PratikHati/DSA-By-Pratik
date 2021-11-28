#include<iostream>
using namespace std;
int main(){

    int start=1;
    int i=0,j=0;
    while(i<4){
        j=0;
        while(j<=i){
            cout<<start<<" ";
            j++;
            start++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}