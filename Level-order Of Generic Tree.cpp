#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    vector<Node*>children;
};

Node *newNode(int key){
	Node *temp=new Node;
	temp->data=key;
	return temp;

}

Node *construct(int arr[],int n ){
    Node *root=NULL;
    stack<Node*>st;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node *t=newNode(arr[i]);
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root=t;
            }
            st.push(t);
        }
    }
    return root;
}

void levelorder(Node *node)
{
    //write your code here
    queue<Node*>q;
    q.push(node);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(curr->data == -1){
            continue;
        }

        cout<<curr->data<<" ";
        
        for(int i=0;i<curr->children.size();i++){
            q.push(curr->children[i]);
        }
    } 
    cout<<".";
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root=construct(arr,n);
    levelorder(root);
}