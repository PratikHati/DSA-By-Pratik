string isFibo(long n) {
  long i = 0;
  long j = 1;
  long m = 1e15+7;
  
  while(n >= i+j){
    
    if(n == i+j){
      return "IsFibo";
    }
    
    long help = i;
    i = j;
    j = ((help%m) + (j%m))%m;
  }
  
  return "IsNotFibo";
}