#include"iostream"
#include<queue>
using namespace std;
main(){
    priority_queue<int> pq;//bydefault max heap
    pq.push(10);
    pq.push(20);

    pq.push(30);
    pq.push(40);

    pq.push(70);
    pq.push(90);

    cout<<pq.size()<<endl;
    while(!pq.empty()){     //does not aure that array will be sorted
        cout<<pq.top()<<" ";
        pq.pop();
    }

}