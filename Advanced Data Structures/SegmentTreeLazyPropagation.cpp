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
    // query zero based, lazy propagation implememted.
    // Update adds delta to the range l, r 
    // query returns max value in the range l, r.

    // nodes 1 based (dw if only using superficially)
    int N;
    vector<int> t;
    vector<int> a;
    vector<int> lazy; 

    
    SegTree(vector<int> &a){
        this->a = a;
        N = a.size();
        t = vector<int> (4 * N + 1);
        lazy = vector<int> (4 * N + 1);
        build(1, 0, N - 1);
    }

    void build(int v, int tl, int tr) {
        if(tl == tr) 
            t[v] = a[tl];
        
        else {
            int tm = (tl + tr) / 2;
            
            build(v * 2, tl, tm);
            
            build(v * 2 + 1, tm + 1, tr);

            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
    void push(int v) {
        t[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        t[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }


    void Update(int l, int r, int delta){
        update(1, 0, N - 1, l, r, delta);
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    int Query(int l, int r){
        return query(1, 0, N - 1, l, r);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -infinity;
        if (l <= tl && tr <= r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(query(v*2, tl, tm, l, min(r, tm)), 
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

};

void slv(){
        vi a = {-1, 2, 1, 3, 7, 8, -9, 0, 4, 15};

        SegTree T(a);

        cout << T.Query(0, 0) << endl;

        T.Update(0, 2, 5); 

        cout << T.Query(0, 2) << endl;
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