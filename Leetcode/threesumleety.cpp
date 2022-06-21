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
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            while(i and i < nums.size() and nums[i] == nums[i - 1]) i++;
            
            for(int j = i + 1, k = (int)nums.size() - 1; j < k;){
                if(nums[j] + nums[k] == -(nums[i])){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < nums.size() and nums[j] == nums[j - 1]) j++;
                    while(k >= 0 and nums[k] == nums[k + 1]) k--;
                }
                else if(nums[j] + nums[k] < -(nums[i]))
                    j++;
                else 
                    k--;
            }
        }
        return ans;
    }
};

int32_t main(){
        FIO 

        return 0;
}
