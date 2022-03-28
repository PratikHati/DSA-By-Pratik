
#include<iostream>
#include<string.h>
using namespace std;


void String_compression01(string str)
{
   //write your code here 
   int n = str.length();
   cout<<str[0];
   for(int i=1;i<n;i++){
      if(str[i] != str[i-1]){
         cout<<str[i];
      }
   }
   cout<<endl;
}
void String_compression02(string str)
{
   //write your code here
   int count = 1;
   int n = str.length();
   cout<<str[0];
   for(int i=1;i<n;i++){
      if(str[i] == str[i-1]){
         count++;
      }
      else{
         if(count == 1){
            cout<<str[i];
         }
         else{
            cout<<count;
            cout<<str[i];
            count =1;
         }
      }
   }
   if(count !=1)
      cout<<count;
   cout<<endl;
}

int main()
{
    string str;
    getline(cin,str);
    String_compression01(str);
    String_compression02(str);
}