#include<bits/stdc++.h>
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define cout std::cout
#define cin std::cin
#define safe_unordered_map(int, T) unordered_map<int, T, custom_hash>

using namespace std;


int lookupSparseTable(vector<vi>& table, int l, int r){

    int n=1;

    int count = 0;

    while(n<<1 < (r-l+1)) n <<= 1, count++;

    return __gcd(table[count][l], table[count][r - n + 1]);
    
}

MOD_DEFINE
int32_t main(){
    vi in = {4, 3, 2, 2};
            //1, 2, 3, 4, 5, 6, 7, 8, 9
    int lg = 1;

    while((1 << lg) < sz(in)) lg++;

    vector<vi> sparseTable(lg + 1, vi(sz(in)+1));

    for(int i = 1; i < sz(in)+1; i++){sparseTable[0][i] = in[i - 1];}

    // 1 based indexing
    for(int i = 0; i < lg; i++)
        for(int j = 1; j < sz(in) - (1<<i) + 1; j++){

            sparseTable[i+1][j] = __gcd(sparseTable[i][j], sparseTable[i][j + (1<<i)]);
        } 

    int l, r;

    cin >> l >> r;
    cout << lookupSparseTable(sparseTable, l, r) << endl;
}
