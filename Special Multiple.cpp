long mysolve(long start,int n){
  
  queue<long> q;
  q.push(9);
  
//use queue instead of recursion to save space

  while(!q.empty()){
    
    long data = q.front();
    q.pop();
    
    if(data > LONG_MAX/10){
      return -1;
    }
    
    if(data % n ==0){
      return data;
    }
    
    q.push(data * 10);
    q.push(data * 10 + 9);
  }s
  
  return -1;
}
string solve(int n) {
  
  
  
  long long int ans = mysolve(9,n);
  
  cout<<ans<<endl;
  
  string str = "";
  
  while(ans){
    int number = ans % 10;
    ans /= 10;
    if(number == 0)
      str.push_back('0');
    else if(number == 9)
      str.push_back('9');
  }
  
  reverse(str.begin(),str.end());
  
  return str;
}
