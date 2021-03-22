#include"bits/stdc++.h"
using namespace std;
vector<vector<int>> ans;//global ans vector
main()
{
    int n;
    cin>>n;//size of input

    vector<int> qns(n);//qns vector of size n

    for(auto &x : qns)//& bcz write operation has to perform
    {
        cin>>x;//take input for qns vector
    }

    sort(qns.begin(),qns.end());//first sort qns vector

    //LOGIC
    do{
        ans.push_back(qns);
    }while(next_permutation(qns.begin(),qns.end()));

    for(auto a : ans)//to print ans vector
    {
        for(auto b : a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }

}