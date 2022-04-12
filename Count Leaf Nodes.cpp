int count(BinaryTreeNode<int> *root,int c){
	
	if(root == NULL){
		return 0;
	}
	
	if(root->left != NULL || root->right != NULL){
		int l = count(root->left,c);
		int r = count(root->right,c);
		
		return l+r;
	}
	
	else{
		return 1;
	}
	
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
	return count(root,0);
}