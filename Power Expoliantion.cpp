#include"iostream"
using namespace std;
int power(int a, int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=power(a,b/2);

    if(b%2==0){
        return ans*ans;
    }
    else{
        return ans*ans*a;
    }
}
int main(){
    cout<<power(2,11)<<endl;
    return 0;
}