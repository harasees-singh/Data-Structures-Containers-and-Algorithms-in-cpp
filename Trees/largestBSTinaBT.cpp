// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE
template <typename T>
class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this->data = data;
                left = NULL;
                right = NULL;
}
};
int32_t main(){
        FIO 

        return 0;
}

int mx = 1;

// #include<pair>
#define pii pair<int, int>
// {min, max}
bool is_bst(int root, pii left, pii right){
    	return (root > left.second) and (root < right.first);
}

pair<int, pii> help(BinaryTreeNode<int> *root){
    	if(!root)
            	return make_pair(0, make_pair(INT32_MAX, INT32_MIN));
		
    	pair<int, pii> left = help(root->left);
    	pair<int, pii> right = help(root -> right);
    
    	pii l = left.second;
    	pii r = right.second;
    	
		int h = 0;
    	if(is_bst(root->data, l, r)){
            	h = max(left.first, right.first) + 1;
            	mx = max(mx, h);
        }
    	if(h == 0){
            	return {INT32_MIN, {INT32_MIN, INT32_MAX}};
        }
    	pair<int, pii> ret;
    	ret.first = h;
    	ret.second = {min(min(l.first, r.first), root->data), max(max(l.second, r.second), root->data)};
    	return ret;
    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    	help(root);
    
    	return mx;
}