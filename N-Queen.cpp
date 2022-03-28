#include<bits/stdc++.h>
using namespace std;
void printpossiblepos(int row,int n,int arr1[],int arr2[],int arr3[],string ans){

    if(row == n){
        cout<<ans<<"."<<endl;
        return;
    }

    for(int i=0;i<n;i++){

        if(arr1[i] == false && arr2[i+row] == false && arr3[row-i+n-1] == false){
            arr1[i] = true;
            arr2[i+row] = true;
            arr3[row-i+n-1] = true;

            string temp = to_string(row)+"-"+to_string(i)+", ";
            printpossiblepos(row+1,n,arr1,arr2,arr3,ans+temp);

            arr1[i] = false;
            arr2[i+row] = false;
            arr3[row-i+n-1] = false;
        }
        
    }

    return;
}
void NQueen(int n){

    int *arr1 = new int[n];
    int *arr2 = new int[2*n - 1];   
    int *arr3 = new int[2*n - 1];
    
    for(int i=0;i<2*n-1;i++){
        arr2[i] = false;
        arr3[i] = false;
        if(i<n)
            arr1[i] = false;
    }

    string ans = "";

    printpossiblepos(0,n,arr1,arr2,arr3,ans);

    return;
}
int main()
{
    int n;
    cin>>n;

    NQueen(n);
    return 0;
}