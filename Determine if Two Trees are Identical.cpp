bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2==NULL){
            return true;
        }
        
        if(r1 == NULL || r2==NULL){
            return false;
        }
        //Your Code here
        if(r1->data != r2->data){
            return false;
        }
        
        bool a = isIdentical(r1->left,r2->left);
        

        bool b = isIdentical(r1->right,r2->right);
        
        return a&b;
    }