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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

int match(string &s, string &t){
    int cnt = 0; 

    for(int i = 0; i < s.size(); i++){
        if(s.substr(i, t.size()) == t) cnt++;
    }
    return cnt;
}

int32_t main(){

    string s = "cagagtaacttcccaaaatcaacattcaagtgtcctgttagtggaggcca";

    vector<string> test = {"gaagagtctt", "aaccatgccg", "gggtcgcgtt"};

    for(int i = 0; i < 3; i++)
        cout << match(s, test[i]) << ' '; cout << endl;

    vector<string> random = {"gaagagtcttctttagaaccatgccgatttcaaacgatagaccatggaattcg", "gtcctaggagaaccatgccgatcaaagagcagtatgaaccatgccgttggtat", "ataagtacctgggtcgcgttcagttgggtcgcgttagggtcgcgttccactcc", "gtcttctttaggggtcgcgttgggtcgcgttccccttggggatttcaaacgatagaccatggaatt", "aagagtcttctttagaaaccccttggggatttcaaacgataga"};

    for(auto p : random){
        for(int i = 0; i < 3; i++)
            cout << match(p, test[i]) << ' ';
        cout << endl;
    }

    return 0;
}
