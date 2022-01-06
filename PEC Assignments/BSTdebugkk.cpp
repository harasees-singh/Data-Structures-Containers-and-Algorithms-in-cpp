#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class BST{
    public:
    BinaryTreeNode<int>* root;

    private:

    BinaryTreeNode<int>* insertNode(int data,BinaryTreeNode<int>* node){
        if(!node){
            BinaryTreeNode<int>* newNode= new BinaryTreeNode<int>(data);
            return newNode;
        }
        // values smaller than or equal to the node are added to the left subtree
        if(node->data>=data) node->left = insertNode(data,node->left);
        else node->right=insertNode(data,node->right);
        return node;     
    }

    BinaryTreeNode<int>* deleteNode(int data,BinaryTreeNode<int>* node){
        if(!node)return NULL;
        if(node->data>data){
            node->left = deleteNode(data,node->left);
            return node;
        }
        else if(node->data<data){
            node->right=deleteNode(data,node->right);
            return node;
        }
        // if(node->data==data)
        else{
            if(!node->left && !node->right){
                delete node;
                return NULL;
            }
            else if(node->left && !node->right){
                BinaryTreeNode<int>* temp = node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else if(node->right){
                BinaryTreeNode<int>* temp = node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode=node->right;
                while(minNode->left)minNode=minNode->left;
                int rightMin=minNode->data;
                node->right=deleteNode(rightMin,node->right);
                return node;
            }
        }
    }

    bool searchData(BinaryTreeNode<int>* node,int data){
        if(!node) return false;
        if(node->data==data)return true;
        if(node->data<data)return searchData(node->right,data);
        else return searchData(node->left,data);
    }

    void preorder(BinaryTreeNode<int>* node){
        if(!node)return;
        cout<<node->data<<' ';
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(BinaryTreeNode<int>* node){
        if(!node)return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<' ';
    }

    void inorder(BinaryTreeNode<int>* node){
        if(!node)return;
        inorder(node->left);
        cout<<node->data<<' ';
        inorder(node->right);
    }

    void level_order(BinaryTreeNode<int>* node){
        if(!node)return;
        queue<BinaryTreeNode<int>*> q;
        q.push(node);
        while(!q.empty()){

            int sz=q.size();
            while(sz){
                BinaryTreeNode<int> *front=q.front();
                cout<<front->data<<' ';
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                sz--;
            }
            cout<<endl;
        }
    }

    public:
    BST(){
        root=NULL;
    }

    ~BST(){
        delete root;
    }

    void insertNode(int data){
        this->root=insertNode(data,root);
        return;
    }

    void deleteNode(int data){
        root=deleteNode(data,root);
        return;
    }

    bool searchData(int data){
        bool found=searchData(root,data);
        return found;
    }

    void preorder(){
        preorder(root);
        return;
    }

    void postorder(){
        postorder(root);
        return;
    }

    void inorder(){
        inorder(root);
        return;
    }

    void level_order(){
        level_order(root);
        return;
    }
};

int main(){
    BinaryTreeNode<int> r(4);

    BST B;

    B.root = &r;

    B.insertNode(3);
    B.insertNode(5);
    B.insertNode(6);

    B.level_order();
}