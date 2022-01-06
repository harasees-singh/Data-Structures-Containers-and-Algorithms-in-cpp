void visit(BinaryTreeNode<int> *root, int depth){
    	if(!root)
            	return;
    	// cout << root->data << endl;
    	if(!depth){
            	cout << root->data << endl;
            	return;
        }
    	depth--;
    	visit(root->left, depth);
    	visit(root->right, depth);
    	
            	
}
int K;

int dfs(BinaryTreeNode<int> *root, int node){
    	if(!root)
            	return -1;
    	if(root->data == node){
            
            	// cout << "OK" << endl;
            
                visit(root->left, K - 1);
                visit(root->right, K - 1);
            
            	return 1;
    	}
    
    	int l = dfs(root->left, node);
    	int r = dfs(root->right, node);
    	if(l == -1 and r == -1)	
            	return -1;
    	K--;
    	if(K < 0)
            	return -1;
    	
    	if(K == 0){
            	cout << root->data << endl; return 1;
        }
		
    	if(l != -1){
                visit(root->right, K - 1);
        }
    	if(r != -1){
            	visit(root->left, K - 1);
        }
    	return 1;
    	
}


void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
		
    	
    	K = k;
    	
    	dfs(root, node);
}