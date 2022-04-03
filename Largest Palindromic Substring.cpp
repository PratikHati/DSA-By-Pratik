#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

string BiggestPalindrom(string qn){

    int n =qn.length();
    string str = qn;    
    reverse(qn.begin(),qn.end());
    
    //check if palindrom exists greater than 1 length
  

    int ** matrix = new int*[n+1];
    for(int x=0;x<n+1;x++){
        matrix[x] = new int[n+1];       //2D matrix
    }

    int length = 0;         //maintain heighest palindrom length
    int row,col;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            
            if(i==0 || j==0){
                matrix[i][j] = 0;
            }

            else if(qn[i] == str[j]){
                matrix[i][j] = matrix[i-1][j-1] + 1;

                if(length < matrix[i][j]){
                    length = matrix[i][j];
                    row = i;
                    col = j;
                }
            }
            else{
                matrix[i][j] = 0;       //substring should be contineous
            }
        }
    }

    if(length <= 1){
        return "";
    }

    string ans = "";
    //answar string exists
    while(matrix[row][col] != 0){
        ans.push_back(qn[row]);
        row--;
        col--;
    }

    return ans;
}
int main()
{
    string qn;
    cin>>qn;
    int n = qn.length();
    cout<<BiggestPalindrom(qn);
    return 0;
}