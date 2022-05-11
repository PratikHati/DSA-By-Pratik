vector<int> topView(Node *root)
    {
        //Your code here
        map<int, int> m;
        
        vector<int> ans;
        
        queue<pair<Node*, int>> q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> curr = q.front();
            
            q.pop();
            
            Node *n = curr.first;
            int hd = curr.second;
        
            
            if(m.find(hd) == m.end()){
                m[hd] = n->data;
            }
            
            if(n->left){
                q.push(make_pair(n->left, hd-1));
            }
            
            if(n->right){
                q.push(make_pair(n->right, hd+1));
            }
        }
        
        
        for(auto x: m){
            ans.push_back(x.second);
        }
        
        
        return ans;
    }
