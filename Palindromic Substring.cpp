#include<iostream>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    printallpalindrome(str);
    return 0;
}

bool isPalindrom(string curr){

  int n = curr.length();
  for(int i=0;i<n/2;i++){

    if(curr[i] != curr[n-i-1]){
      return false;
    }
  }

  return true;
}
void printallpalindrome(string str)
{
  //write your code here
  //print all possible substring

  int n = str.length();

  for(int i=0;i<n;i++){
    
    for(int j=i+1;j<=n;j++){
      
      int length = j-i;
      string curr = str.substr(i,length);
      
      if(isPalindrom(curr)){
        cout<<curr<<endl;
      }
    }
  }
}

