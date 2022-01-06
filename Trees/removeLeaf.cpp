BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(!root) return NULL;
    
    bool noleaf = (root->left) or (root->right);
    
    if(!noleaf){
        	return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}