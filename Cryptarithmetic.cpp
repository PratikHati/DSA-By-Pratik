#include<bits/stdc++.h>
using namespace std;
int GetSum(string s1,unordered_map<char,int> &um){
    int n = s1.length();

    int sum = 0;
    for(int i=0;i<n;i++){
        sum = (sum*10) + um[s1[i]];
    }

    return sum;
}
void Cryptarithmetic(unordered_map<char,int> &um,string unique,int idx,vector<bool> &b, string s1,string s2, string s3){
    
    //base case
    if(idx > unique.length()){
        return;
    }
    if(idx == unique.length()){
        int carry = 0;
        int l1 = GetSum(s1,um);
        int l2 = GetSum(s2,um);
        int l3 = GetSum(s3,um);


        if(l1+l2 == l3){
            for(int i=0;i<26;i++){
                char c = 'a'+i;
                if(um.find(c) != um.end()){
                    cout<<c<<"-"<<um[c]<<" ";
                }
            }
            cout<<endl;
        }

        return;
    }

    for(int i=0;i<10;i++){
        
        if(b[i] == false){
            um[unique[idx]] = i;
            b[i] = true;
            Cryptarithmetic(um,unique,idx+1,b,s1,s2,s3);
            b[i] = false;
            um[unique[idx]] = -1;
        }
    }

    return;
}
int main() {
    string s1,s2,s3;

    cin>>s1;
    cin>>s2;
    cin>>s3;
    string unique = "";

    unordered_map<char,int> um;

    for(int i=0;i<s1.size();i++){
        if(um.find(s1[i]) == um.end()){
            um[s1[i]] == -1;
            unique.push_back(s1[i]);
        }
    }

    for(int i=0;i<s2.size();i++){
        if(um.find(s2[i]) == um.end()){
            um[s2[i]] == -1;
            unique.push_back(s2[i]);
        }
    }

    for(int i=0;i<s3.size();i++){
        if(um.find(s3[i]) == um.end()){
            um[s3[i]] == -1;
            unique.push_back(s3[i]);
        }
    }

    vector<bool> b(10,false);
    sort(unique.begin(),unique.end());
    Cryptarithmetic(um,unique,0,b,s1,s2,s3);

    return 0;
}