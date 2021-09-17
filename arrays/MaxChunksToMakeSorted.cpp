#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define Set                             tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

using namespace std;
MOD_DEFINE

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int cnt = 0, maxima = 0;

        // 0, 4, 2, 1, 3, 6, 5

        // max chunks possible : 

        // {0}, {4, 2, 1, 3}, {6, 5}
        
        for(int i = 0; i < arr.size(); i++){
                
            maxima = max(maxima, arr[i]);
        
            if(maxima == i)  cnt++, maxima = 0;
        }
        
        return cnt;
    }
};
