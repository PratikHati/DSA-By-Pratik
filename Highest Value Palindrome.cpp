#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
string maxstring(string s1, string s2){
  int a = stoi(s1);
  int b = stoi(s2);
  
  if(a>b){
    string ans = to_string(a);
    return ans;
  }
  string ans = to_string(b);
  return ans;
}
bool palindrom(string s){
  int n = s.length();
  
  for(int i=0;i<n/2;i++){
    if(s[i] != s[n-i-1]){
      return false;
    }
  }
  
  return true;
}
string isPalindrom(string str, int s, int e, int k){
  
  if(s>e){
    return str;
  }
  if(k < 0){
    return "-1";
  }
  
  if(k == 0){
    if(palindrom(str)){
      return str;
    }
    return "-1";
  }
  
  //update to max of(str[s],str[e])
  char c = max(str[s],str[e]);
  
  if(str[s] == c && str[e] == c){
    
    string ans1 = isPalindrom(str,s+1,e-1,k);     //already palindrom
    
    if(c == '9'){
      return ans1;
    }
    string temp = str;
    temp[s] = '9';
    temp[e] = '9';
    string maxans1 = isPalindrom(temp,s+1,e-1,k-2);    //9---9 included
    
    return maxstring(ans1,maxans1);
  }
  
  else{
    string temp = str;
    temp[s] = c;
    temp[e] = c;
    string ans2 =  isPalindrom(temp,s+1,e-1,k-1);   //1 updated to palindrom
    
    if(c == '9'){
      return ans2;
    }
    string temp2 = str;
    temp2[s] = '9';
    temp2[e] = '9';
    string maxans2 = isPalindrom(temp2,s+1,e-1,k-2); //9-----9  included
    
    return maxstring(ans2,maxans2);
  }
  
}
string highestValuePalindrome(string s, int n, int k) {
  
  return isPalindrom(s,0,n-1,k);
}
int main()
{
    int a,b;
    cin>>a>>b;

    string ans;
    cin>>ans;

    cout<<highestValuePalindrome(ans,ans.length(),b)<<endl;
    return 0;
}

