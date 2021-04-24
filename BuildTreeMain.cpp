#include<iostream>
using namespace std;
#include"BuildTree_Inorder_Preorder.h"
int main(){
    int inorder[]={4,2,1,5,3};
    int preorder[]={1,2,4,3,5};

    node *r=buildTree(inorder,preorder,0,4);

    inorderPrint(r);
    
    return 0;
}