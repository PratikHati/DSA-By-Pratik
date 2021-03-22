#include"iostream"
#include"queue"
#include"stack"
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

void preorder_Ittr(node *t)//preorder by itterative data->left->right
{
    stack<node *> s;//create a stack of node *
    
    cout<<"Pre order is ";
    while(!s.empty() || t)
    {
        if(t)       //if t is not null
        {
            cout<<t->data<<" ";//print data
            s.push(t);//store root node in stack
            t=t->left;//move to left child
        }
        else
        {
            t=s.top();//pop from stack
            s.pop();
            t=t->right;//move to right
        }
    }
}
void inorder_Ittr(node *t)//inorder by itterative left->data->right
{
    stack<node *> s;//create a stack of node *

    cout<<"In order is ";
    while(!s.empty() || t)//till t!=NULL or stack is not empty
    {
        if(t)       //if t is not null
        {
            s.push(t);//store root node in stack
            t=t->left;//move to left child
        }
        else
        {
            t=s.top();//pop from stack
            s.pop();
            cout<<t->data<<" ";//print data
            t=t->right;//move to right
        }
    }
}
// void postorder_Ittr(node *t)//postorder by itterative left->right->data
// {
//     stack<node *> s;//create a stack of node *
//     long int i;//to store address in both + vs and - ve

//     cout<<"Post order is ";
//     while(!s.empty() || t)//till t!=NULL or stack is not empty
//     {
//         if(t)       //if t is not null
//         {
//             s.push(t);//store root node in stack
//             t=t->left;//move to left child
//         }
//         else
//         {
//             i=s.top();//pop from stack
//             s.pop();
//             if(i>0)     //if left node, move to right by storing in stack
//             {
//                 //------IMPORTANT--------
//                 s.push((node *)-i);         //Again pushback into stack
//                 t=((node *)i)->right;//move to right and remember to typecast it
//             }
//             else
//             {
//                 cout<<((node *)i)->data<<" ";//print data
//                 t=NULL;//make t null
//             }
            
//         }
//     }

// }

// vector<int> postorder_new(Node *root)//same as above but we used data instead of memory address
// {
//     vector<int> v;
//     stack<Node *> s;
//     Node *i;                 //store address 
//     Node *t;
//     t=root;
    
//     while(!s.empty() || t)
//     {
//         if(t)                   //t!=NULL
//         {
//             s.push(t);
//             t=t->left;
//         }
//         else                    //t==NULLsigned 
//         {
//             i=s.top();    //explicite conversion
//             s.pop();
//             if((i->data)>0)             //to go right child
//             {
//                 i->data=-(i->data);
//                 s.push(i);     //store -i so that we can know left child is visited
//                 t=i->right;//move t to right child
//             }
//             else                //store it in vector and make t=NULL
//             {
                
//                 v.push_back(-(i->data));
//                 t=NULL;
//             }
//         }
//     }
    
//     return v;
// }
int max(int a,int b)
{
    return a<b ? b: a;
}
int heightTree(node *p)
{
    if(p!=nullptr)
    {
        int h1=heightTree(p->left);
        int h2=heightTree(p->right);
        if(h1<h2)
        {
            return h2+1;
        }
        else
        {
            return h1+1;
        }
    }
    return 0;
}
int diameterTree(node *p)
{
    if(p==NULL)
        return 0;
    else
    {
        int h1=heightTree(p->left);
        int h2=heightTree(p->right);

        int d1=diameterTree(p->left);
        int d2=diameterTree(p->right);

        return max((h1+1+h2),max(d1,d2));
    }
}
main()
{
    createTree();
    //preorder_Ittr(root);
    //inorder_Ittr(root);
    //cout<<heightTree(root)<<endl;
    cout<<diameterTree(root)<<endl;
    return 0;
}