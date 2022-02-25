//Check if array is rotated multiple times, it can be sorted or not?

string larrysArray(vector<int> A) {
  //use INVERSION SET THEORY
  int n=A.size();
  int inv=0;
  for(int i=0;i<n-1;i++){
    for(int j=i;j<n;j++){
      if(A[i]>A[j]){
        inv++;
      }
    }
  }
  
  if(inv%2 == 0){
    return  "YES";
  }
  return "NO";
}