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

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    void propagate(TrieNode *root, string word, string formation, bool print, int id){
        if(!root) return;
        if(word == formation){
            if(root->isTerminal)
            cout << word << endl;
            
            for(int i = 0; i < 26; i++){
                	auto call = root->children[i];
                	if(call) propagate(call, word, formation + call->data, true, 8);
            }
            return;
        }
        if(print){
            if(root->isTerminal)
            cout << (formation) << endl;
            
            for(int i = 0; i < 26; i++){
                	auto call = root->children[i];
                	
                	if(call) propagate(call, word, formation + call->data, true, 9);
            }
            return;
        }
        char need = word[id];
        for(int i = 0; i < 26; i++){
                	auto p = root->children[i];
                	if(p and p->data == need){
                	propagate(p, word, formation + need, false, id + 1);
            	}
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        for(auto p : input)
            insertWord(p);
        propagate(root, pattern, "", false, 0);
    }
};

int32_t main(){
        FIO 

        return 0;
}
