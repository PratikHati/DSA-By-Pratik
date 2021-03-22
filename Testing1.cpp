#include"iostream"
#include"deque"
#include"vector"
using namespace std;
main()
{
    // deque<int> d;
    // d.clear();
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v2.push_back(10);
    v3=v1+v2;
}