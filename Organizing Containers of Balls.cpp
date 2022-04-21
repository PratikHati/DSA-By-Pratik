string organizingContainers(vector<vector<int>> container) {
  
  int n = container.size();
  vector<int> row(n,0);
  vector<int> col(n,0);  
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      
      row[i] = row[i] + container[i][j];
      col[i] = col[i] + container[j][i];  //important
    }
  }
  
  sort(row.begin(),row.end());
  sort(col.begin(),col.end());
  
  for(int i=0;i<n;i++){
      if(row[i] != col[i]){
        return "Impossible";
      }
  }
  
  return "Possible";
}
