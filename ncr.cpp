#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */
long long int modulomulti(int x, int r, int p){
  
  x = x%p;
  long long int ans = 0;
  
  while(r){
    if(r%2 == 1){
      
      ans = (ans + x) %p;  
    }
    
    x = (2 * x) % p;
    r = r/2;
  }
  
  return ans;
}
long long int moduloGCD(long long int a, long long int b, long long int *x, long long int *y){
  
  if(a==0){
    *x = 0;
    *y = 1;
    return b;
  }
  
  long long int p,q;
  
  long long int gcd  = moduloGCD(b%a, a, &p, &q);
  
  *x = q - (b/a) * p;
  *y = p ;
  
  return gcd; 
}
long long int moduloinversion(int r,int p){
  
  long long int x,y;
  
  long long int gcd = moduloGCD(r,p, &x, &y);
  
  if(gcd != 1){
    return -1;
  }
  
  return ((x % p)+ p )%p;
}

long long int modulodevide(int n,int r,int p){
  
  n = n%p;
  long long int inv = moduloinversion(r, p);
  
  if(inv != -1){
    return (n * inv)%p;
  }
  else{
    return 0;
  }
}

int combination(int n,int r, int p){
  
  if(r > n){
    return 0;
  }
  if(n-r < r){
    r = n-r;
  }
  
  long long int x = 1;
  
  for(int i=1; i<=r ;i++){
    
    x = modulomulti(x, n-i+1 , p);
    
    x = modulodevide(x, i, p);
  }
  
  return x;
}

vector<int> solve(int n) {
  
  vector<int> ans;
  for(int i=0; i<= n/2 ;i++){
    ans.push_back(combination(n,i,1000000007));
  }
  
  for(int j=(n/2)+1;j<=n;j++){
    ans.push_back(ans[n-j]);
  }
  return ans;
}

int main()
{
    int t;
    cin>>t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        
        int n;

        cin>>n; 

        vector<int> result = solve(n);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}

