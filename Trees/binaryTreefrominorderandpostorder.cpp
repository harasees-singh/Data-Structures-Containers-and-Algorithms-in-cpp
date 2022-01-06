int Find(int x, int* arr, int start, int end){
    	for(int i = start; i <= end; i++){
            	if(arr[i] == x) return i;
        }
}


BinaryTreeNode<int>* help(int postStart, int postEnd, int inStart, int inEnd, int* post, int* in){
    	if(postStart > postEnd) return NULL;
    	
    	int root = post[postEnd];
    
    	auto it = new BinaryTreeNode<int> (root);
    
    	int id = Find(root, in, inStart, inEnd);

    	it->left = help(postStart, postEnd - (inEnd - id + 1), inStart, id - 1, post, in);
	
    	it->right = help(postEnd - (inEnd - id), postEnd - 1, id + 1, inEnd, post, in);
    
    	return it;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
		return help(0, postLength - 1, 0, postLength - 1, postorder, inorder);
}