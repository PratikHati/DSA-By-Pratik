void myfunc(Node *root, vector<bool> &hash, int vd,vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(hash[vd] == false){
        ans.push_back(root->data);
        hash[vd] = true;
    }
    
    //call left
    myfunc(root->left,hash,vd+1,ans);
    //call right
    myfunc(root->right,hash,vd+1,ans);
}
vector<int> leftView(Node *root)
{
   // Your code here
   
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   ans.push_back(root->data);
   
   vector<bool> hash(101,false);
   
   int vd = 0;
   hash[vd] = true;
   
   if(root->left){
       myfunc(root->left,hash,vd+1,ans);
   }
   if(root->right){
       myfunc(root->right,hash,vd+1,ans);
   }
   
   return ans;
   
}