vector<int> absolutePermutation(int n, int k) {
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    ans[i] = i+1;
  }
  if(k == 0){
    return ans;
  }
  
  if(n%2 != 0){
    vector<int> temp;
    temp.push_back(-1);
    return temp;
  }
  
  if(n%(2*k) == 0){
    for(int i=0;i<n;i+=2*k){
      for(int j=1;j<=k;j++){
        swap(ans[i+j-1], ans[i+j-1+k]);
      }
    }
    
    return ans;
  }
  vector<int> temp;
  temp.push_back(-1);
  return temp;
}
