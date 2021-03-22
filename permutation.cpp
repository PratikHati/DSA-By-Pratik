#include"bits/stdc++.h"//bcz swap() will be used, else we can explicitely make swap()
using namespace std;

vector<vector<int>> ans;//global answer 2D vector , so that everyone can access

void permute(vector<int> &qns/*pass by reference*/ ,int i)//permutation func()
{
    if(i==qns.size())//base case
    {
        ans.push_back(qns);
        return;
    }
    for(int x=i;x<qns.size();x++)//loop to itterate through qns vector
    {
        //logic 
        swap(qns[x],qns[i]);
        permute(qns, i+1);
        swap(qns[x],qns[i]);
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    
    vector<int> qns(n);//qns vector
    
    for(auto &v : qns)//& because write operation has to be performed
    {
        cin>>v;//value automatically taken inside vector as it is foreach loop
    }

    permute(qns,0); //O(n) time complexity
    
    for(auto y : ans)//No & as only read from ans vector
    {
       for(auto z : y)//No & as only read from ans vector
       {
           cout<<z<<" ";
       }
       cout<<endl;
    }
}
