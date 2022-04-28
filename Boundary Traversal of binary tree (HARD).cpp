void choseLeft(Node *root, vector<int> &ans){
        
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right != NULL){
            ans.push_back(root->data);
            return choseLeft(root->right,ans);
        }
        else if(root->left == NULL && root->right == NULL)
            return;
        ans.push_back(root->data);
        
        return choseLeft(root->left,ans);
    }
    void choseChild(Node *root, vector<int> &ans){
        
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        choseChild(root->left,ans);
        choseChild(root->right,ans);
    }
    void choseRight(Node *root, vector<int> &ans){
        
        if(root == NULL){
            return;
        }
        
        if(root->right == NULL && root->left != NULL){
            ans.push_back(root->data);
            return choseRight(root->left,ans);
        }
        else if(root->left == NULL && root->right == NULL)
            return;
        ans.push_back(root->data);
        
        return choseRight(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return ans;
        }
        
        ans.push_back(root->data);
        //ans.pop_back();
        if(root->left){
            choseLeft(root->left,ans); 
        }
        
        //prnt all child of root
        choseChild(root,ans);
        
        //prnt right-skewed of root in reverse
        if(root->right){
            
            vector<int> help;
            choseRight(root->right,help); 
            reverse(help.begin(),help.end());
            for(auto x: help){
                ans.push_back(x);
            }

        }
        
        
        return ans;
    }