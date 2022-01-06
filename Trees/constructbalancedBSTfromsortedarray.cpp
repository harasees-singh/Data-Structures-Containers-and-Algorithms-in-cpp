BinaryTreeNode<int>* help(int l, int r, int* in){
    if(l > r) return NULL;
    int mid = (l + r)/2;
    auto root = new BinaryTreeNode<int> (in[mid]);
    
    root -> left = help(l, mid - 1, in);
    root -> right = help(mid + 1, r, in);
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
		return help(0, n - 1, input);
}