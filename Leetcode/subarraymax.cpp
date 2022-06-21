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
int ans = 0;
vector<vector<int>> dp;
// faster approach in O(1) space
// int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
//         int l = -1, r = -1;
//         int ans = 0;
//         for(int i = 0; i < nums.size(); i++){
//                 if(nums[i] > right) l = i;

//                 if(nums[i] >= left) r = i;

//                 ans += (r - l);
//         }
//         return ans;
// }
int get(int n){
        // if(n < 0) return 0;
        return n * (n + 1) / 2;
}
void find(vector<int>& nums, int i, int j, int left, int right){
        if(i > j) return;

        int cur = i;

        int mx = i;

        for(int i = 16; i >= 0; i--){
                if(cur + (1 << i) <= j){
                        mx = (nums[mx] < nums[dp[cur][i]] ? dp[cur][i] : mx);
                        
                        cur = cur + (1 << i);
                }
        }
        assert(mx >= i and mx <= j);

        if(nums[mx] <= right and nums[mx] >= left){
                ans += get(j - i + 1) - get(mx - i) - get(j - mx);
        }
        find(nums, i, mx - 1, left, right); 
        
        find(nums, mx + 1, j, left, right);
}
int numSubarrayBoundedMax(vector<int>& nums, int left, int right){
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(17, n));

        nums.push_back(-1);

        for(int i = n - 1; i >= 0; i--){
                dp[i][0] = (nums[i] > nums[i + 1] ? i : i + 1);
                for(int j = 1; j < 17; j++){

                        int go = min(i + (1 << (j - 1)), n - 1);
                        assert(go < n);
                        int id = dp[go][j - 1];
                        int compete = dp[i][j - 1];
                        // cout << "OK" << endl; cout.flush();
                        dp[i][j] = (nums[id] > nums[compete] ? id : compete);
                }
        }
        find(nums, 0, n - 1, left, right);
        return ans;
}

int32_t main(){
        FIO 

        vi nums;

        int n; cin >> n;

        nums.resize(n); for(auto &p : nums) cin >> p;

        int left, right; cin >> left >> right;

        cout << numSubarrayBoundedMax(nums, left, right) << endl;

        for(auto p : dp){
                for(auto q : p){
                        cout << q << ' ';
                }
                cout << endl;
        }

        return 0;
}
