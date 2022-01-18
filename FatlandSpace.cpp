#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.

int flatlandSpaceStations(int n, vector<int> c) {
    
  int size=c.size();
  int arr[n]={-1};
  int arr2[n]={-1};
  int count1=INT_MAX;
  int count2=INT_MAX;

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
    if(count1!=INT_MAX)
      count1++;
  }
  
  for(int j=n-1;j>=0;j--){
    
    if(arr2[j]!=0){
      arr2[j]=count2;
    }
    if(arr2[j]==0){
      count2=0;
    }
    if(count2!=INT_MAX){
      count2++;
    }
  }
  
  int ans=INT_MIN;
  for(int i=0;i<n;i++){
    
    arr[i]=min(0,min(arr[i],arr2[i]));
    ans=max(ans,arr[i]);
  }
  
  return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
