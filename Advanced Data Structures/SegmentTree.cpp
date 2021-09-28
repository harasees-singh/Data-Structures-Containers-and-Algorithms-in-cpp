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
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

int n = 10;

int T[40];

void build(vi &a, int v, int tl, int tr){
    // v being the current tree node number.
    // tl and tr being the left and right boundaries of indices that node v will store the answer to
    if(tl == tr)
            T[v] = a[tl];
    
    else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);

            T[v] = T[v*2] + T[v*2 + 1];
    }
}

int QuerySum(int v, int tl, int tr, int l, int r){

        if(tl >= l and tr <= r) 
                return T[v];
        if(tr < l or tl > r)
                return 0;
                
        int mid = (tl + tr)/2;

        return QuerySum(2*v, tl, mid, l, r) + QuerySum(2*v + 1, mid + 1, tr, l, r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) 
                T[v] = new_val;

        else{
                int tm = (tl + tr) / 2;

                if (pos <= tm)
                        update(v*2, tl, tm, pos, new_val);
                else
                        update(v*2+1, tm+1, tr, pos, new_val);
                        
                T[v] = T[v*2] + T[v*2+1];
        }
}
int32_t main(){
    FIO 

    vi a = {0, 1, -1, 2, -2, 4, 4, 1, 1, 6, -6};

        build(a, 1, 1, 10);

        update(1, 1, 10, 1, 5);

        for(int i = 0; i < 40; i++)
                cout << T[i] << ' '; cout << endl;

        cout << QuerySum(1, 1, 10, 1, 1) << endl;

    return 0;
}
