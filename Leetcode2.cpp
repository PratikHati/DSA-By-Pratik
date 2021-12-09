#include<bits/stdc++.h>
using namespace std;
int reverse(int x) {
        
    int y=x;
    int ans=0;
    int digit=0;
        
    while(y!=0){
        int temp=y%10;
        if(ans>(INT_MAX/10) || ans<(INT_MIN/10)){
            return 0;
        }
        ans=(ans*10)+temp;
        y/=10;
        digit++;
    }
        
    if(x<0){
        int temp=ans*(-1);
        return temp;
    }
    else
        return ans;   
        
}
    
int main(){
    //int ans=reverse(-123);
    int ans=(-1)*234;
    cout<<ans<<endl;
    return 0;
}
