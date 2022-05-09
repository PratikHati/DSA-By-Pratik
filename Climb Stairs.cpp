#include<iostream>
#include<vector>

using namespace std;

int ClimbStairs(int n, vector<int> &v){

    if(v[n] != -1){
        return v[n];
    }

    int one = ClimbStairs(n-1,v);
    int two = ClimbStairs(n-2,v);
    int three = ClimbStairs(n-3,v);

    v[n] = one+two+three;
    return v[n];
}
int main() {

    int n;
    cin>>n;

    vector<int> v(n+1,-1);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    cout<<ClimbStairs(n,v);
    return 0;
}