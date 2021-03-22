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
void preorder(node *p)//preorder traversal
{
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}
void inorder(node *p)//inorder traversal
{
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}
void postorder(node *p)//postorder traversal
{
    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<" ";
}
int sumOfAllnodes(node *p)//sum of all nodes
{
    if(p)
    {
        int x=sumOfAllnodes(p->left);
        int y=sumOfAllnodes(p->right);
        return x+y+p->data;
    }
    return 0;
}
void levelOrder(node *p)//level by level
{
    if(p==NULL)
        return;
    
    queue<node *> q;//queue needed to store nodes
    cout<<p->data<<" ";
    q.push(p);//push root into queue
    node *temp;//temp node
    

    while(!q.empty())//while queue is full
    {
        temp=q.front();//pop and store int temp queue
        q.pop();//pop it
        if(temp->left)//if left node present
        {
            cout<<temp->left->data<<" ";//print it
            q.push(temp->left);//then push it into queue
        }
        if(temp->left)//if right node present
        {
            cout<<temp->right->data<<" ";//print it
            q.push(temp->right);//push right node to queue
        }
    }


}
int countNodes(node *p)//no of nodes of a tree
{
    if(p)
    {
        int x=countNodes(p->left);//count for left
        int y=countNodes(p->right);//count for right
        return x+y+1;
    }
    return 0;
}
int leafNodes(node *p)//count no of leaf nodes
{
    if(p->left==NULL && p->right==NULL)
        return 1;
    int x=leafNodes(p->left);
    int y=leafNodes(p->right);
    return x+y;
}
int onechild(node *p)//count no of nodes of a child
{
    if(p)
    {
        int x=onechild(p->left);
        int y=onechild(p->right);
        if(p->left==NULL || p->right==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
main()
{   
    createTree();//create tree function
    // preorder(root);//print tree preorder
    // inorder(root);//inorder traversal
    // postorder(root);//postorder traversal
    //levelOrder(root);
    cout<<leafNodes(root)<<endl;//no of leaf nodes
}