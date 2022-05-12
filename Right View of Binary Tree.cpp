void myfunc(Node *root, vector<int> &ans, int vd, vector<bool> &hash){
        if(root == NULL){
            return;
        }
        
        if(hash[vd] == false){
            ans.push_back(root->data);
            hash[vd] = true;
        }
        
  
        myfunc(root->right, ans, vd+1, hash);
    
        myfunc(root->left, ans, vd+1, hash);

        
        return ;
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       if(root == NULL){
           return ans;
       }
       ans.push_back(root->data);
       int vd = 0;
       vector<bool> hash(100000+7, false);
       hash[vd] = true;
       
       if(root->right){
           myfunc(root->right,ans,vd+1,hash);
       }
       if(root->left){
           myfunc(root->left,ans,vd+1,hash);
       }
       
       return ans;
    }