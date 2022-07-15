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
struct SparseTable{
    // 1 based indexing
    vector<vector<int>> M;
    vector<vector<int>> Midx;
    int lg = 1;
    vector<int> in;

    SparseTable(vector<int> &I){
        in = I;

        while((1 << lg) < sz(in)) lg++;

        M = vector<vector<int>> (lg + 1, vector<int> (sz(in) + 1));
        Midx = vector<vector<int>> (lg + 1, vector<int> (sz(in) + 1));

        for(int i = 1; i < sz(in) + 1; i++)
            Midx[0][i] = i - 1;
        
        for(int i = 1; i < sz(in) + 1; i++)
            M[0][i] = in[i - 1];

        for(int i = 0; i < lg; i++)
            for(int j = 1; j < sz(in) - (1 << i) + 1; j++)
                Midx[i + 1][j] = (in[Midx[i][j]] < in[Midx[i][j + (1 << i)]] ? Midx[i][j] : Midx[i][j + (1 << i)]);
            
        for(int i = 0; i < lg; i++)
            for(int j = 1; j < sz(in) - (1 << i) + 1; j++)
                M[i + 1][j] = min(M[i][j], M[i][j + (1 << i)]);
        
    }

    int readidx(int l, int r){
        assert(l <= r and l > -1);

        int n = 1, count = 0;

        while(n << 1 < (r - l + 1)) n <<= 1, count++;

        return in[Midx[count][l]] < in[Midx[count][r - n + 1]] ? Midx[count][l] : Midx[count][r - n + 1];
    }
    int read(int l, int r){
        assert(l <= r and l > -1);
        
        int n = 1, count = 0;
      
        while(n << 1 < (r - l + 1)) n <<= 1, count++;

        return min(M[count][l], M[count][r - n + 1]);
    }
};

MOD_DEFINE
int32_t main(){
    vi in = {4, 3, 2, 0};
            //1, 2, 3, 4, 5, 6, 7, 8, 9
    SparseTable T(in);

    cout << T.read(1, 3) << endl;

    cout << T.readidx(2, 4) << endl; 
}
