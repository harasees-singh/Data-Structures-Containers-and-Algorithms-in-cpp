#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

struct Node{
    int val;

    Node *left, *right;

    Node(int data){
        val = data;

        left = NULL, right = NULL;
    }
    ~Node(){
        // deleting left and right subtree before deleting a node recursively
        delete left;
        delete right;
    }
};

struct BinarySearchTree{
    Node *root;

    BinarySearchTree(int root){
        this->root = new Node(root);
    }
    ~BinarySearchTree(){
        // when this destructor is called it deletes the entire tree recursively by using a depth first traversal.
        delete root;
    }
    void Insert(int n){
        insert(n, this->root, NULL);
    }
    void insert(int n, Node *root, Node *parent){
        if(root == NULL){
            if(parent->val > n) parent->left = new Node(n);

            else parent->right = new Node(n);

            return;
        }
        if(root->val > n){
            // go left
            insert(n, root->left, root);
        }
            // go right
        else insert(n, root->right, root);
    }
    Node *findval(int n, Node *root){
        if(root == NULL) return NULL;

        if(root->val == n) return root;

        if(root->val > n) return findval(n, root->left); else return findval(n, root->right);
    }
    Node *findparent(int n, Node* root){
        if(root->right and root->right->val == n or root->left and root->left->val == n) return root;

        if(root->val > n) return findparent(n, root->left); 

        else return findparent(n, root->right);
    }   
    Node *findmaxsubtree(Node* root){
        // keep going right
        if(root->right) return findmaxsubtree(root->right);
        // when u reach the righmost node return it
        return root;
    }
    void deleteNode(int n){
        // locate the node to be deleted
        Node * deleteme = findval(n, this->root);

        if(!deleteme){
            cout << "Node not found" << endl; return;
        }

        if(deleteme->right and deleteme->left){
            // if node has 2 children find the right most node in the left subtree or the left most node in the right subtree and swap the two
            Node * rightmostleafinleftsubtree = findmaxsubtree(deleteme->left);
            int t = rightmostleafinleftsubtree->val;
            // after saving it's value delete it.
            deleteNode(t);
            // assign it's value to the node that was supposed to be deleted
            deleteme->val = t;

            return;
        }
        if(deleteme->right or deleteme->left){
            // corner case if this->root is to be deleted and it is part of a linear chain

            if(this->root == deleteme){
                Node* t = this->root;

                this->root = (this->root->left ? this->root->left : this->root->right);

                // to this->root assign it's immediate child and then delete it from memory
                t->left = t->right = NULL;
                // making sure both it's children are NULL so that we don't end up deleting it's entire subtree
                delete t;
                return;
            }
            // find the parent of the node to be deleted.
            Node * Parent = findparent(n, this->root);

            (Parent->left == deleteme ? Parent->left : Parent->right) = (deleteme->left ? deleteme->left : deleteme->right);
            // assign the child of the node to be deleted to it's parent as it's new child.
            deleteme->left=deleteme->right=NULL;
            // delete it finally
            delete deleteme; return;
        }
        // no children means leaf
        Node *P = findparent(n, this->root);
        (P->left->val == n ? P->left : P->right) = NULL;
        delete deleteme;
    }
    void levelOrderTraversal(){
        queue<Node *> Q;

        if(this->root == NULL) return;
        
        Q.push(root);

        while(Q.empty() == 0){
            int s = Q.size();
            while(s--){
                auto p = Q.front();

                cout << p->val << ' ';

                Q.pop();

                if(p->left) Q.push(p->left); if(p->right) Q.push(p->right);
            }
            cout << endl;
        }
        cout << endl;
    }
    void In(Node *root){
        if(!root) return;
        In(root->left); cout << root->val << " "; In(root->right);
    }
    void Pre(Node *root){
        if(!root) return;
        cout << root->val << " "; Pre(root->left); Pre(root->right);
    }
    void Post(Node *root){
        if(!root) return;
        Post(root->left); Post(root->right); cout << root->val << " ";
    }
    void InOrderTraversal(){
        if(this->root == NULL) return;
        In(this->root); cout << endl;
    }
    void PreOrderTraversal(){
        if(this->root == NULL) return;
        Pre(this->root); cout << endl;
    }
    void PostOrderTraversal(){
        if(this->root == NULL) return;
        Post(this->root); cout << endl;
    }
};

int32_t main(){
    FIO 

    BinarySearchTree B(4);

    B.Insert(3);
    B.Insert(6);
    B.Insert(5);
    B.Insert(7);
    B.Insert(8);
    B.Insert(2);
    B.Insert(1);

    B.levelOrderTraversal();

    B.deleteNode(4);

    B.PreOrderTraversal();

    B.PostOrderTraversal();

    B.InOrderTraversal();

    B.deleteNode(6);

    B.levelOrderTraversal();

    B.Insert(6);

    B.levelOrderTraversal();

    return 0;
}
