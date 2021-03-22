#include"bits/stdc++.h"
using namespace std;
vector<vector<int>> ans;//2D global vector 
void logic(vector<int> qns, vector<vector<int>> &ans,int index)
{
    if(index==qns.size())//base case
    {
        ans.push_back(qns);
        return;
    }

    for(int i=index;i<qns.size();i++)
    {
        if(i!=index && qns[i]==qns[index])//to block repeating permutations
            continue;
        swap(qns[i],qns[index]);
        logic(qns,ans,index+1);
    }
    return;
}
void permute(vector<int> qns)
{
    logic(qns,ans,0);//another func()due to limitation of online method signature
}
main()
{
    int n;
    cin>>n;

    vector<int> qns(n);//memory allocate to vector of n size

    for(auto &x : qns)
    {
        cin>>x;
    }

    permute(qns);//permute func() call

    for(auto y : ans)//print ans vector
    {
        for(auto z : y)
        {
            cout<<z<<" ";
        }
        cout<<endl;
    }


}