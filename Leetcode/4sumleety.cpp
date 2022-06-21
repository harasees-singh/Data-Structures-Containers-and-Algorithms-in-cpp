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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(i and i < n and nums[i] == nums[i - 1]) i++;
            
            for(int j = i + 1; j < n; j++){
                while(j > i + 1 and j < n and nums[j] == nums[j - 1]) j++;
                
                if(j >= n) break;
                
                int need = target - (nums[i] + nums[j]);
                
                for(int pt1 = j + 1, pt2 = n - 1; pt1 < pt2;){
                    if(need == nums[pt1] + nums[pt2]){
                        ans.push_back({nums[i], nums[j], nums[pt1], nums[pt2]});
                        pt1++, pt2--;
                        while(pt1 < n and nums[pt1] == nums[pt1 - 1]) pt1++;
                        while(pt2 >= 0 and nums[pt2] == nums[pt2 + 1]) pt2--;
                    }
                    
                    else if(need < nums[pt1] + nums[pt2]){
                        pt2--;
                    }
                    else 
                        pt1++;
                }
            }
        }
        return ans;
    }
};
int32_t main(){
        FIO 

        return 0;
}
