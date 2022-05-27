int pairs(int k, vector<int> arr) {
  unordered_map<int,bool> umap;
  int count = 0;
  for(int i=0;i<arr.size();i++){
    if(umap[arr[i] - k] == true){
      count++;
    }
    if(umap[arr[i] + k] == true){
      count++;
    }
    
    umap[arr[i]] = true;
  }
  
  return count;
}