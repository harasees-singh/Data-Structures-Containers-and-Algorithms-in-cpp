int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(!root) return false;
 	
    int ok = (root->data > x);
    
    for(int i = 0; i < root->children.size(); i++) ok += getLargeNodeCount(root->children[i], x);
    
    return ok;
}