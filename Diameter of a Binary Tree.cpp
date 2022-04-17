int diameter2(struct Node* root, int *dm){
    if(root == NULL){
        return 0;
    }
    
    int l = diameter2(root->left,dm);
    int r = diameter2(root->right,dm);
    
    if(l+r+1 > *dm){
        *dm = l+r+1;
    }
    
    return max(l,r)+1;
}
int diameter(struct Node* root) {
    // code here
    if(root == NULL){
        return 0;
    }
    
    int dm = 0;
    int x = diameter2(root, &dm);
    return dm;
}