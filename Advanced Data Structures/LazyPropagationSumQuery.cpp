// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
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
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(T)                            int T; cin >> T; while(T--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE

struct SegTree{

    vector<int> t, a, lazy; 
    int N;
    SegTree(vector<int> &in){
        a = in;
        N = in.size();

        t = vector<int> (4 * N + 5);

        lazy = vector<int> (4 * N + 5);

        build(1, 0, N - 1);
    }   
    void build(int node, int start, int end)
    {
        if(start == end){
            t[node] = a[start];
        }
        else{
            int mid = (start + end) / 2;

            build(2 * node, start, mid);

            build(2 * node + 1, mid + 1, end);

            t[node] = t[2 * node] + t[2 * node + 1];
        }
    }
    void Update(int l, int r, int delta){
        updateRange(1, 0, N - 1, l, r, delta);
    }

    void updateRange(int node, int start, int end, int l, int r, int val){
        if(start > end or start > r or end < l)              
            return;

        if(lazy[node] != 0){

            t[node] += (end - start + 1) * lazy[node];    
            if(start != end){

                lazy[node * 2] += lazy[node];                  
                
                lazy[node * 2 + 1] += lazy[node];                
            }
            lazy[node] = 0;                                  
        }
        if(start >= l and end <= r){
            t[node] += (end - start + 1) * val;
            if(start != end)
            {
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, val);        
        updateRange(node * 2 + 1, mid + 1, end, l, r, val);  
        t[node] = t[node * 2] + t[node * 2 + 1];        
    }

    int Query(int l, int r){
        return queryRange(1, 0, N - 1, l, r);
    }

    int queryRange(int node, int start, int end, int l, int r){
        if(start > end or start > r or end < l)
            return 0;         

        if(lazy[node] != 0)
        {
            t[node] += (end - start + 1) * lazy[node];            
            if(start != end)
            {
                lazy[node*2] += lazy[node];         // Mark child as lazy
                lazy[node*2+1] += lazy[node];    // Mark child as lazy
            }
            lazy[node] = 0;                 // Reset it
        }
        if(start >= l and end <= r)             
            return t[node];
        int mid = (start + end) / 2;

        return (queryRange(node * 2, start, mid, l, r) + queryRange(node * 2 + 1, mid + 1, end, l, r));
    }
};

void slv(){
    vi a = {-1, 0, 3, 1, 0};
    SegTree T(a);
    
    cout << T.Query(0, 2) << endl;

    T.Update(0, 2, 1);

    cout << T.Query(1, 3) << endl;
}

int32_t main(){
        
        FIO

        slv();
        
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/