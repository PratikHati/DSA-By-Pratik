#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void RabinKarp(string qn,string ans,int prime, int size){       

    int n = qn.length();
    int m = ans.length();
    int h = 1;
    int x=0;        //qn[]
    int y=0;        //ans[]
   //hash ans till m-1
    for(int i=0;i<m-1;i++){
        h = (h*size)% prime;
    }

   //hash ans and qn till m and n
    for(int i=0;i<m;i++){
        
        x = (size*x+qn[i])%prime;
        y = (size*y+ans[i])%prime;
    }
   //loop to check and rehash
   for(int i=0;i<n;i++){
       if(x==y){
           bool flag = false;
           
           for(int j=0;j<m;j++){
               if(ans[j] != qn[i+j]){
                   flag = true;
                   break;
               }
           }

           if(flag == false){
               cout<<i<<endl;
           }

       }

        //rehash x
       if(i < n-m){
           x = (size*(x - qn[i]*h) + qn[i+m])%prime;

           if(x<0){
               x = x+prime; //no idea... see GFG
           }
       }
   }
}   
int main()
{

    string qn = "GEEKS FOR GEEKS";
    string ans = "GEEK";
  
    RabinKarp(qn,ans,101,256);  //101 is a prime used for moduloarithmatic and 256 any char heighest ASCII 
    return 0;
}