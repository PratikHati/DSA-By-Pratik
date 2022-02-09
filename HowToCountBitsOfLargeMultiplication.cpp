double logB2(int a){
    return log(a)/log(2);
}
int multipleLength(vector<int> &a, int n) {
    // Write your code here.
    double count=1.0;
    for(int i=0;i<n;i++){
        count+=logB2(a.at(i));
    }
    
    int ans=count;
    return ans;
}

  