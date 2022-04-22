
string encryption(string s) {

  string real_s = "";
  for(int i=0;i<s.length();i++){
    if(s[i] != ' '){
      
      real_s.push_back(s[i]);
    }
  }
  
  int n = real_s.length();
  
  int x = ceil(sqrt(n)); //rows

  int y = 0;   //cols
  
  if(x*(x-1) >= n){
    y = x-1;
  }else{
    y = x;
  }
  
  int first = min(x,y);
  int second = max(x,y);
  
  string ans = "";
  
  for(int i=0;i<second;i++){
    
    for(int j=0;j<first;j++){
      
      int index = i+(j*second);
      
      if(index < n)
        ans.push_back(s[i+(j*second)]);
    }
    ans.push_back(' ');
  }
  
  return ans;
}