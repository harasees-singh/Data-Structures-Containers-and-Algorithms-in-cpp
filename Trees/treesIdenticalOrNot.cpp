
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(!root1 and !root2) return true;
    
    if(!root1 or !root2) return false;
    
    if(root1 -> data != root2 -> data) return false;
    
    bool ok = true;
    
    if(root1 -> children.size() != root2 -> children.size()) return false;
    
    for(int i = 0; i < root1->children.size(); i++) ok = ok and areIdentical(root1->children[i], root2->children[i]);
    
    return ok;
}