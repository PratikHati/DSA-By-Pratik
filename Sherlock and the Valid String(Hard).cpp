#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
  int *arr = new int[26];
  for(int i=0;i<26;i++){
    arr[i] = 0;
  }
  
  int n = s.length();
  
  for(int i=0;i<n;i++){
    int index = s[i] - 97;
    arr[index] += 1;
  }
  
  
  unordered_map<int,int> m;
  for(int i=0;i<26;i++){
    
    if(arr[i] != 0){
      m[arr[i]] = m[arr[i]]+1;   
    }
  }
  
  if(m.size() > 2){
    return "NO";
  }
  int helper = -1;
  
  if(m.size() == 2){
    //very very important
    int data1 ;
    int data2 ;
    
    int count1 ;
    int count2 ;
    
    int j = 0;
    for(auto x :m){
      if(j==0){
        data1 = x.first;
        count1 = x.second;
      }
      else{
        data2 = x.first;
        count2 = x.second;
      }
      j++;
    }
    
    if(count1 == 1){
      if(data1-1 == data2 || data1-1 == 0){
        return "YES";
      }
      return "NO";
    }
    if(count2 == 1){
      if(data2-1 == data1 || data2-1 == 0){
        return "YES";
      }
      return "NO";
    }
    else{
      return "NO";
    }
  }
  if(m.size() == 1){
    return "YES";
  }
  
  return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
