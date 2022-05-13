void myfunc(Node *root,map<int, vector<int>> &m,int idx){
    if(root == NULL){
        return;
    }
    
    m[idx].push_back(root->data);
    
    myfunc(root->left,m,idx+1);
    
    myfunc(root->right,m,idx);

}
vector<int> diagonal(Node *root)
{
   // your code here
   map<int, vector<int>> m;
   vector<int> ans;
   
   myfunc(root,m,0);
   
   for(auto x: m){
       for(auto y:x.second){
           ans.push_back(y);
       }
   }
   
   return ans;
}