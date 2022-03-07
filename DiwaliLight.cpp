long lights(int n) {
  
  long ans = 1;
  int m = 100000 ;
  
  for(int i=1;i<=n;i++){
    ans = ((ans%m) *2)%m ;
  }
  
  return ans - 1;
}
