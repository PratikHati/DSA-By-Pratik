int height(Node *root){
        if(root == NULL){
            return 0;
        }
        
        int l = height(root->left);
        int r = height(root->right);
        
        return max(l,r)+1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == NULL){
            return true;
        }
        
        int l = height(root->left);
        int r = height(root->right);
        
        if(abs(l-r) > 1){
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
    }