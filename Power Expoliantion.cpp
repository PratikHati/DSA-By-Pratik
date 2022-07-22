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
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0){
            return 1;
        }
        
        if(n==1){
            return x;
        }
        
        int N = n;
        if(n<0){
            
            if(n != INT_MIN)
                n = n*(-1);
            else
            {
                if(x==1 || x== -1)
                    return 1;
               
                return 0;
            }
        }
        
        double d = myPow(x,n/2);
        
        if(n%2==0){
            double db = d*d;
            if(N<0)
                return 1/db;
            return db;
            
        }
        else{
            double db = d*d*x;
            if(N<0)
                return 1/db;
            return db;
        }
        
        
    }
};
int main(){
    cout<<power(2,11)<<endl;
    return 0;
}