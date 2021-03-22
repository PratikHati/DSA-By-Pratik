#include"iostream"
#include"queue"
using namespace std;
//use nullptr instread of null
//NULL= (char *)0 can't be converted to integral types
//nullptr= is a keyword which is same to null but can be implicitely convertible to integral types

class node
{
    public:
        node *right;
        int data;
        node *left;
        node(int data)//parameterised constructor
        {
            this->data=data;
            this->left=this->right=NULL;
        }
};


node *root=nullptr;//global
//use nullptr instead of NULL
void createTree()
{
    node *p,*t1,*t2;              //create 3 nodes
    int x,y;                              //to store root data
    cout<<"Enter root data"<<endl;      //ask root data
    cin>>x;                             //root data
    root=new node(x);                   //memory allocate to root
    queue<node*> q;                     //create a queue to keep a track
    q.push(root);                      //push root into queue

    while(!q.empty())
    {
        p=q.front();
        q.pop();                      //pop from queue and store in p node
        cout<<"Enter left data of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)                       //valid non negetive number
        {
            t1=new node(x);              //create t node
            p->left=t1;                  //connect t with *left of p
            q.push(t1);                 //push t into queue
        }
        cout<<"Enter right data "<<p->data<<endl;
        cin>>y;
        if(x!=-1)
        {
            t2=new node(y);
            p->right=t2;
            q.push(t2);
        }
    }
}

void printBy
