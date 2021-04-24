
class node{
    public:
    int data;
    node *left,*right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(int inorder[],int preorder[], int fi,int li){
    
    if(fi>li){
        return NULL;//base case
    }
    //take a static variable to traverse preorder array
    static int idx=0;//initially only once it will execute

    int curr=preorder[idx];
    node *root=new node(curr);//create a node
    idx++;//even if in recursion idx will increase as it is static
    if(fi==li){
        return root;
    }

    int curradr=0;//non static
    while(inorder[curradr]!=curr){
        curradr++;          //address of curr in inorder[]
    }

    root->left= buildTree(inorder,preorder,fi,curradr-1);
    root->right=buildTree(inorder,preorder,curradr+1,li);

    return root;
}

void inorderPrint(node *root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
