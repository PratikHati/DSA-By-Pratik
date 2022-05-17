pair<int,int> myfunc(Node *root, int height){
        
        pair<int,int> l;
        pair<int,int> r;
        if(root->left == NULL && root->right == NULL){
            return make_pair(height,root->data);
        }
        if(root->left){
            l = myfunc(root->left,height+1);
           
        }
        if(root->right){
            r = myfunc(root->right,height+1);
        }
        
        if(l.first == r.first){     //same height
            if(l.second > r.second){
                l.second += root->data;
                return l;
            }
            r.second += root->data;
            return r;
        }
        
        if(l.first > r.first){
            l.second += root->data;
            return l;
        }
        r.second += root->data;
        return r;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        pair<int,int>p;
        p = myfunc(root,0);
        
        return p.second;
    }