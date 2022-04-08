#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


bool isMagicSquare(vector<int> &v){
  //v has 9 elements, so for easy design , covert it to 3*3 first
  vector<vector<int>> temp(3, vector<int>(3,0));
  int x= 0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      
      temp[i][j] = v[x];
      x++; 
    }
  }
  //check row sum
  int checkrow = 0;
  for(int i=0;i<3;i++){
    checkrow += temp[0][i];
  }
  
  for(int i=1;i<3;i++){
    int row = 0;
    for(int j=0;j<3;j++){
      
      row += temp[i][j];
    }
    
    if(row != checkrow){
      return false;
    }
  }
  
  //check col sum
  
  for(int i=1;i<3;i++){
    int col = 0;
    for(int j=0;j<3;j++){
      
      col += temp[j][i];
    }
    
    if(col != checkrow){
      return false;
    }
  }
  
  //check \ diagonal
  int dig1 = 0;
  for(int i=0;i<3;i++){
    
    dig1 += temp[i][i];
  }
  if(dig1 != checkrow){
    return false;
  }
  
  //check / diagonal 
  int dig2 = 0;
  for(int i=0;i<3;i++){
    
    int second = abs(2-i);
    dig2 += temp[i][second];
  }
  if(dig2 != checkrow){
    return false;
  }
  
  
  return true;
}
void AllMagicSquare(vector<vector<int>> &ans){
  
  vector<int> v {1,2,3,4,5,6,7,8,9};
  
  do{
    
    if(isMagicSquare(v)){
      ans.push_back(v);
    }
    
  }while(next_permutation(v.begin(),v.end()));
}
int CalculteDiff(vector<int> &ans, vector<vector<int>> &qn){
  int a = 0;
  
  int diff = 0;
  for(int i=0;i<qn.size();i++){
    for(int j=0;j<qn[i].size();j++){
      
      diff += abs(qn[i][j]-ans[a]);
      a++;
    }
  }
  
  return diff;
}

int formingMagicSquare(vector<vector<int>> s) {
  
  vector<vector<int>> ans;
  AllMagicSquare(ans);
  
  int minans = INT_MAX;
  int size = ans.size();
  
  for(int i=0;i<size;i++){
    
    minans = min(minans, CalculteDiff(ans[i],s));
  }
  
  return minans;
}

int main()
{
    //see HackerRank
}
