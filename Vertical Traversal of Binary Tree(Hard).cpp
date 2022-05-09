vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,map<int ,vector<int>>> m;      //horizontal, vertical, vector
        
        queue<pair<Node *, pair<int,int>>> q;   //Node ,hd, vd
        
        vector<int> ans;
        
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()){
            
           pair<Node *, pair<int,int>> p = q.front();
           q.pop();
           
           Node *n = p.first;
           int hd = p.second.first;
           int vd = p.second.second;
           
           
           m[hd][vd].push_back(n->data);
           
           if(n->left){
               q.push(make_pair(n->left, make_pair(hd-1, vd+1)));
           }
           
           if(n->right){
               q.push(make_pair(n->right, make_pair(hd+1, vd+1)));
           }
        }
        
        //rememebr, m is already sorted
        for(auto x: m){
            //x is a int, map
            for(auto y: x.second){      //y is int, vector
                
                for(auto z: y.second){      //z is vector
                    ans.push_back(z);
                }
            }
        }
        
        return ans;
    }