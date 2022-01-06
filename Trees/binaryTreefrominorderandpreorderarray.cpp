int Find(int x, int* arr, int start, int end){
    	for(int i = start; i <= end; i++){
            	if(arr[i] == x) return i;
        }
}

BinaryTreeNode<int>* help(int preStart, int preEnd, int inStart, int inEnd, int *pre, int *in){
    
    	if(preStart > preEnd) return NULL;
    
    	int id;
    
    	int root = pre[preStart];
    
    	auto it = new BinaryTreeNode<int>(root);
    
    	id = Find(root, in, inStart, inEnd);
    
    	it->left = help(preStart + 1, preStart + id - inStart, inStart, id - 1, pre, in);
    
    	it->right = help(preStart + id - inStart + 1, preEnd, id + 1, inEnd, pre, in);
    
    	return it;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
    	return help(0, preLength - 1, 0, preLength - 1, preorder, inorder);
}