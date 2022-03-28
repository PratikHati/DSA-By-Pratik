#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int MaxScore(int n, vector<string> &s, int k, vector<int> &count, vector<int> &score, int index){

   if(index == n){
       return 0;
   } 

   //do not include
    int dino = MaxScore(n,s,k,count,score,index+1);

   //include
    int dinc = 0;
    string word = s[index];
    int len = word.length();
    bool flag = false;

    for(int i=0;i<len;i++){

        char c = word[i];

        if(count[c - 'a'] == 0){
            flag = true;
        }

        count[c - 'a']--;   //decrement a count

        dinc += score[c - 'a'];
    }

    int dinc2 = 0;
    if(flag == false){

        dinc2 = dinc+ MaxScore(n,s,k,count,score,index+1);
    }
   
        //redo all changes or backup
        for(int i=0;i<len;i++){

            char c = word[i];

            count[c - 'a']++;   //increament a count
        }


    return max(dinc2, dino);
}
int main()
{
    int n;
    cin>>n;
    vector<string> str;

    string s ;
    for(int i=0;i<n;i++){
        cin>>s;
        str.push_back(s);
    }

    int k;
    cin>>k;

    vector<int> count(26,0);
    char c;
    for(int i=0;i<k;i++){
        cin>>c;
        count[c - 'a'] += 1;    //store count
    }

    vector<int> score(26,0);
    int d;
    for(int i=0;i<26;i++){
        cin>>d;
        score[i] = d;
    }

    cout<<MaxScore(n,str,k,count,score,0)<<endl;
    return 0;
}