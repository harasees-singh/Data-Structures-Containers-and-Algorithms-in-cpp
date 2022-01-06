// ਹਰਅਸੀਸ ਸਿੰਘ 
// 4th December 2021

// Adelson-Velskii and Landis Tree
// a type of self balancing binary search tree

#include<iostream>
#include<queue>
using namespace std;

struct Node {

        int key;
        Node *left;
        Node *right;
        int height;

        Node(int x){
                key = x;
                left = NULL;
                right = NULL;
                height = 0;
        }
        ~Node(){
                delete left;
                delete right;
        }
};

int height(Node *N) {
        if(N == NULL)
                return 0;
        return N->height;
}
Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *temp = x->right;
        x->right = y;
        y->left = temp;
        // in case of right rotation we return the left child of the node to be rotated as the new root
        // the right subtree of x is made the new left subtree of y
        // y is made the right child of x
        y->height = max(height(y->left), height(y->right)) + 1;
        // heights are updated to match the changes due to rotation
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
}

Node *leftRotate(Node *y) {
        Node *x = y->right;
        Node *temp = x->left;
        x->left = y;
        y->right = temp;
        // in case of left rotation we return the right child of the node to be rotated as the new root
        // the left subtree of x is made the new right subtree of y
        // y is made the left child of x
        x->height = max(height(x->left), height(x->right)) + 1;
        // heights are updated to match the changes due to rotation
        y->height = max(height(y->left), height(y->right)) + 1;
        
        return x;
}

int BalanceFactor(Node *N) {
        if(!N)
                return 0;
        return height(N->left) - height(N->right);
}

Node *Balance(Node *root){
        if (root == NULL)
                return NULL;

        root->height = 1 + max(height(root->left), height(root->right));

        int balanceFactor = BalanceFactor(root);

        if(balanceFactor > 1) {
                // balance factor greater than 1 means our tree is left heavy
                if (BalanceFactor(root->left) >= 0) {
                        // left-left case can be handled with a single right rotation about the unbalanced node
                        return rightRotate(root);
                } 
                else {
                        // left-right case can be handled by first left rotating the left node of the unbalanced node 
                        // so that the resulting config is left-left
                        root->left = leftRotate(root->left);
                        return rightRotate(root);
                }
        }
        if(balanceFactor < -1) {
                if (BalanceFactor(root->right) <= 0) {
                        // right-right case can be handled with a single left rotation about the unbalanced node
                        return leftRotate(root);
                } 
                else {
                        // right-left case can be handled by first right rotating the right node of the unbalanced node 
                        // so that the resulting config is right-right
                        root->right = rightRotate(root->right);
                        return leftRotate(root);
                }
        }
        return root;
}

Node *insertNode(Node *node, int key) {
        if(!node){
                Node* t = new Node(key);

                return Balance(t);
        }
        if(key < node->key)
                node->left = insertNode(node->left, key);
        else if (key > node->key)
                node->right = insertNode(node->right, key);
        else
                return node;

        return Balance(node);
}

Node *nodeWithMimumValue(Node *node) {
        Node *current = node;
        // keep going left
        // last non-NULL node is the minimum node
        while (current->left != NULL)
                current = current->left;
        return current;
}

Node *deleteNode(Node *root, int key) {
        if (!root)
                return root;
        if (key < root->key)
                root->left = deleteNode(root->left, key);
        else if (key > root->key)
                root->right = deleteNode(root->right, key);
        else{
                // found the node to be deleted
                if ((root->left == NULL) or (root->right == NULL)) {
                        Node *temp = root->left ? root->left : root->right;
                        if (temp == NULL) {
                                // 0 children
                                // simply delete root
                                temp = root;
                                root = NULL;
                        } 
                        else
                                // 1 child
                                // transfer it's contents to root and delete it from memory
                                *root = *temp;
                        temp->right = temp->left = NULL;
                        delete temp;
                } 
                else{
                        // case with both children
                        // find the leftmost node in the right subtree and swap it's contents with the node to be deleted
                        // delete it instead of the root.
                        Node *temp = nodeWithMimumValue(root->right);
                        root->key = temp->key;
                        root->right = deleteNode(root->right, temp->key);
                }
        }
        return Balance(root);
}

void levelOrder(Node* root){
        queue<Node*> q;
        cout << "----------------------------" << endl;
        q.push(root);

        while(q.empty() == false){
                int s = q.size();

                while(s--){
                        auto t = (q.front());

                        q.pop();

                        cout << t->key << ' ';

                        if(t->left) q.push(t->left);
                        if(t->right) q.push(t->right);
                }   
                cout << endl;    
        }
        cout << "----------------------------" << endl;
        cout << endl;
}

int main() {
        Node *root = NULL;
        cout << "to insert a key input 1 <key>" << endl;
        cout << "delete a key input 2 <key>" << endl;
        cout << "to print the tree input 3" << endl;
        cout << "to exit the program input 0" << endl;
        while(true){
                int t; cin >> t;

                if(!t)  
                        break;
                
                if(t == 1){
                        int key; cin >> key;

                        root = insertNode(root, key);
                }
                if(t == 2){
                        int key; cin >> key;

                        root = deleteNode(root, key);
                }
                if(t == 3){
                        cout << endl;
                        levelOrder(root);
                }
        }
        delete root;
        
        return 0;
}