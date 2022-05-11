vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        
        map<int,int> m;     //hd,data
        queue<pair<int, Node*>> q;
        
        q.push(make_pair(0,root));
        
        while(!q.empty()){
            pair<int,Node*> p = q.front();
            q.pop();
            int hd = p.first;
            Node *n = p.second;
            
            m[hd] = n->data;
            
            if(n->left){
                q.push(make_pair(hd-1, n->left));
            }
            
            if(n->right){
                q.push(make_pair(hd+1, n->right));
            }
        }
        
        for(auto x:m){
            ans.push_back(x.second);
        }
        
        return ans;
    }