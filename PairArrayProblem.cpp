#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;
bool myCompare(pair<int ,int>p1,pair<int,int>p2)
{
    return p1.first<p2.first;
}
main()
{
    int arr[]={10,16,7,14,5,3,12,9};//given array
    vector<pair<int,int>> v;//v vector has pair<int ,int>
    
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)//create a vector of pair containing both array[i](values) and i(index)
    {
        v.push_back(make_pair(arr[i],i));//make_array() is used to make pair<int,int>
    }

    sort(v.begin(),v.end(),myCompare);//sort the vector

    for(int i=0;i<v.size();i++)//store index in main array
    {
        arr[v[i].second]=i;//because v[i].second has index and v[i].first has values of array
    }

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cout<<arr[i]<<" ";
    }
}