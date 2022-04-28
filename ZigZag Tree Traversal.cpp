void BFSTraverse(Node *root, int level, vector<pair<Node *,int>> &ans){
        
        if(root == NULL){
            return;
        }
        
        pair<Node *,int> p;
        p.first = root;
        p.second = level;
        
        queue<pair<Node *,int>> q;
        q.push(p);
        
        while(!q.empty()){
            
            pair<Node *,int> d = q.front();
            q.pop();
            
            ans.push_back(d);
            
            if(d.first->left != NULL){
               pair<Node *,int> temp1;
                temp1.first = d.first->left;
                temp1.second = d.second+1; 
                q.push(temp1);
            }
            
            if(d.first->right != NULL){
                pair<Node *,int> temp2;
                temp2.first = d.first->right;
                temp2.second = d.second+1;
                q.push(temp2);
            }
            
        }
        
        return;
    }
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> actual_ans;
    	vector<pair<Node *,int>> ans;
    	int level = 0;
    	
    	BFSTraverse(root,level,ans);
    	
    	stack<int> s;
    	
    	for(auto x: ans){
    	    
    	    if(x.second%2 == 1){
    	        s.push(x.first->data);
    	    }
    	    else{
    	        while(!s.empty()){
    	            int a = s.top();
    	            actual_ans.push_back(a);
    	            s.pop();
    	        }
    	        
    	        actual_ans.push_back(x.first->data);
    	    }
    	}
    	
    	while(!s.empty()){
    	    int a = s.top();
    	    actual_ans.push_back(a);
            s.pop();
    	 }
    	
    	return actual_ans;
    }