void myfunc(Node *root,vector<int> v,int target,int &count){
        if(root == NULL){
            return;
        }
        v.push_back(root->data);
        
        myfunc(root->left,v , target, count);
        myfunc(root->right,v , target, count);
        
        int n = v.size();
        int sum = 0;
        
        for(int i=n-1;i>=0;i--){
            sum += v[i];
            
            if(sum == target){
                count++;
            }
        }
        
        //v.pop_back();
        return;
    }
    int sumK(Node *root,int k)
    {
       
        vector<int> v;
       
        
        int count =0;
        myfunc(root,v,k,count);
        
        return count;
    }