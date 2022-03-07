int summingSeries(long n) {
  
  int m = 1e9 + 7;

  
  return ((n%m)*(n%m))% m;
}
