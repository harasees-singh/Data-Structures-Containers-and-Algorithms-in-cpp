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

struct BinarySearchTree{
    int *arr;
    int N;

    BinarySearchTree(int n = 1000){
        N = n;
        arr = new int[n];
        for(int i = 0; i < N; i++) arr[i] = infinity;
    }

    void insert(int n, int root){
        if(root >= N){
            cout << "BST is out of capacity, can't support insertion " << endl; return;
        }
        if(arr[root] == infinity) {
            arr[root] = n; 
            return;
        }
        if(arr[root] > n){
            insert(n, root*2 + 1);
        }
        else{
            insert(n, root*2 + 2);
        }
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
        for(int i = 0; i < N; i++) if(arr[i] != infinity) cout << arr[i] << ' '; cout << endl;
    }
    int findval(int val, int root){
        if(root >= N or arr[root] == infinity) return false;

        if(arr[root] == val) return true;

        if(arr[root] > val) return findval(val, root*2 + 1);

        else return findval(val, root*2 + 2);
    }
    void deleteNode(int root){
        
    }
};

int32_t main(){
    FIO 

    return 0;
}
