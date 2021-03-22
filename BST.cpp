#include"iostream"
#include"stack"
using namespace std;
struct node
{
    public:
        int data;
        struct node * left;
        struct node * right;
        
};
node *root=NULL;//global
node * RinsertNode(node *p,int d) //recursive
 {
    if(p==NULL)
    {
        p=new node;
        p->data=d;
        p->left=p->right=NULL;
        return p;
    }
    else if(d<(p->data))
        p->left=RinsertNode(p->left,d);
    else if(d>(p->data))
        p->right=RinsertNode(p->right,d);
    
    return p;
 }

void insertNode(int key)
{
    node* t = root;
    node* p;
    node* r;
 
    // root is empty ,create a node root and return
    if (root == nullptr){
        p = new node;
        p->data = key;
        p->left = nullptr;
        p->right = nullptr;
        root = p;
        return;
    }
 
    while(t != nullptr){
        r = t;
        if (key < t->data){
            t = t->left;
        } else if (key > t->data){
            t = t->right;
        } else {
            return;
        }
    }
 
    // Now t points at NULL and r points at insert location
    p = new node;
    p->data = key;
    p->left = nullptr;
    p->right = nullptr;
 
    //link t node to r
    if (key < r->data){
        r->left = p;//use r not t as r contains address of prev node
    } else {
        r->right = p;
    }
 
}

int height(node *p)
{
    if(p)
    {
        int h1=height(p->left);
        int h2=height(p->right);

        if(h1>h2)
            return h1+1;
        else
            return h2+1;
    }
    return 0;
}

node * inorderPredessor(node *p)//move towards right
{
    node *q;
    while(p)
    {
        q=p;
        p=p->right;
    }
    return q;
}

node * inorderSuccessor(node *p)//move towards left
{
    node *q;
    while(p)
    {
        q=p;
        p=p->left;
    }
    return q;
}

//inorder predessor or inorder successor is req to delete a node
node * DeleteNode(node *p,int data)
{
    if(p==NULL)//edge case
    {
        return NULL;
    }
    if(p->left==NULL && p->right==NULL && p->data==data)//if data is at leaf node
    {
        if(p==root)     
            root=NULL;
        free(p);
    }
    if(p->data<data)
    {
        p->left=DeleteNode(p->left,data);
    }
    else if(p->data>data)
    {
        p->right=DeleteNode(p->right,data);
    }
    else if(p->data==data)
    {
        node *q;                //temp node
        if(height(p->left)>height(p->right))
        {
            q=inorderPredessor(p->left);
            p->data=q->data;
            p->left=DeleteNode(p->left,q->data);
        }
        else
        {
            q=inorderSuccessor(p->right);
            p->data=q->data;
            p->right=DeleteNode(p->right,q->data);
        }
    }
    return p;



}
node * generateTreePre(int a[],int size)//array , size of array
{
    stack<node *> st;//to store left child
    int i=0;//to traverse a[]
    root=new node();//alocate memory to root
    root->data=a[i++];
    root->left=root->right=NULL;//left and right initially NULL
    node *t=root;//t node
    node *p;

    // -----STACK may not be empty after this loop, bcz a[] is important not stack
    while(i<size)//traverse a[]
    {
        if(a[i]<t->data)//if left child
        {
            p=new node;//create a new node
            p->left=p->right=NULL;
            p->data=a[i++];//store a[i] in p->data, then i++
            t->left=p;//connect t->left to p
            st.push(t);//push left child into stack
            t=p;//move t to p
            
        }
        else        //if right child
        {   
            if(a[i]>t->data && a[i]<(st.top())->data)   //a[i] greater than t->data but less than (st.top())-> data
            {
                p=new node ;
                p->data=a[i++];
                p->left=p->right=NULL;
                t->right=p;     //IMPORTANT -- right node need not to be push into stack 
                t=p;
            }
            else
            {
                t=st.top();//pop and store it in t node
                st.pop();
            }
        }
    }

}
void inorder(node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
   
}

main()
{
    root=RinsertNode(root,10);
    RinsertNode(root,5);
    RinsertNode(root, 20);
    RinsertNode(root,8);
    RinsertNode(root,30);

    inorder(root);//print
    return 0;
}