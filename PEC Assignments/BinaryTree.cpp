#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
// #define infinity                        999999999999999999
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

#define infinity                        INT32_MAX

struct BinaryTree{
    int *arr;
    int N;
    int cur;

    BinaryTree(int n = 1000){
        N = n;
        arr = new int[n];
        cur = 0;
        for(int j = 0; j < n; j++) 
            arr[j] = infinity;
    }
    ~BinaryTree(){
        // free up the dynamically allocated memory
        delete []arr;
    }

    void insert(int n){
        // insert at cur and then increment it
        arr[cur++] = n;
    } 

    void inOrderTraversal(int root){
        if(root >= N or arr[root] == infinity) return;

        inOrderTraversal(root*2 + 1);

        cout << arr[root] << ' ';

        inOrderTraversal(root*2 + 2);
    }
    void preOrderTraversal(int root){
        if(root >= N or arr[root] == infinity) return;

        cout << arr[root] << ' ';

        preOrderTraversal(root*2 + 1);

        preOrderTraversal(root*2 + 2);
    }
    void postOrderTraversal(int root){
        if(root >= N or arr[root] == infinity) return;

        postOrderTraversal(root*2 + 1);

        postOrderTraversal(root*2 + 2);

        cout << arr[root] << ' ';
    }
    void levelOrderTraversal(int root){
        for(int i = 0; i < cur; i++) {
        
            cout << arr[i] << ' ';

            // if i + 2 is a power of 2 then move to new line as one level is complete.

            if(!((i + 2)&(i + 1))) cout << endl;
        
        }
        cout << endl;
    }
    void deleteNode(int root){
        root = findval(root);
        if(!cur){
            cout << "tree is empty! can't delete non-existent nodes" << endl; 
            return;
        }
        if(root == -1){
            cout << "No such node found" << endl; return;
        }
        // swap the val of node to be deleted with last inserted node
        swap(arr[root], arr[cur - 1]);
        // place infinity in the last node so that it can be reused
        arr[cur - 1] = infinity;
        cur--;
    }
    int findval(int val){
        for(int i = 0; i < cur; i++) if(arr[i] == val) return i; return -1;
    }
};

int32_t main(){
    FIO 

    BinaryTree t;

    for(int i = 0; i < 10; i++){
        t.insert(i + 1);
    }

    t.levelOrderTraversal(0);

    t.inOrderTraversal(0); cout << endl;
    t.preOrderTraversal(0); cout << endl;
    t.postOrderTraversal(0); cout << endl;

    t.deleteNode(6);
    t.deleteNode(8);

    cout << t.findval(9) << endl;

    t.insert(100);

    t.levelOrderTraversal(0);

    return 0;
}
