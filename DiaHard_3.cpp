int HCF(int a,int b){
  if(b == 0){
    return a;
  }
  
  return HCF(b,a%b);
}
string solve(int a, int b, int c) {
  int gcd = HCF(a,b);
  
  if(c < max(a,b) && c%gcd == 0){
    return "YES";
  }
  
  return "NO";
}
