#include <bits/stdc++.h>
using namespace std;

// Complete the flatlandSpaceStations function below.

void flatlandSpaceStations(int n, vector<int> c) {
  int size=c.size();
  int arr[n];
  int arr2[n];
  int count1=-1;
  int count2=-1;

  for(int i=0;i<n;i++){
    arr[i]=-1;
    arr2[i]=-1;
  }

  

  for(int i=0;i<size;i++){

    arr[c.at(i)]=0;   
    arr2[c.at(i)]=0; 
  }
  
  
  for(int i=0;i<n;i++){
   
    if(arr[i]!=0){
      arr[i]=count1;
    }
    if(arr[i]==0){
      count1=0;
    }
    if(count1!=-1)
      count1++;
    
    
  }

  
  
  for(int j=n-1;j>=0;j--){
    
    if(arr2[j]!=0){
      arr2[j]=count2;
    }
    if(arr2[j]==0){
      count2=0;
    }
    if(count2!=-1){
      count2++;
    }
    
  }
  for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
  }

  cout<<endl;
  
  for(int i=0;i<n;i++){
      cout<<arr2[i]<<" ";
  }
  cout<<endl;


  int ans=INT_MIN;
  for(int i=0;i<n;i++){
    
    arr[i]=min(arr[i],arr2[i]);
    ans=max(ans,arr[i]);
    cout<<ans<<" ";
  }
  
  //return ans;
}

int main()
{
    int n=5;
    vector<int> v;
    v.push_back(0);
    v.push_back(4);

    flatlandSpaceStations(n,v);
    return 0;
}
