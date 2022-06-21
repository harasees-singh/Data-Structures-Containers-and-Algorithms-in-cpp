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
    int cmp;
    bool peeche_reh_gaya(int id, vector<int> &arr){
        if(arr[id] < cmp){
            return true;
        }
        return false;
    }
    int search(vector<int>& nums, int target) {
        cmp = nums[0];
        int pivot = 0;
        
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l + r)/2;
            
            if(peeche_reh_gaya(mid, nums)) r = mid - 1;
            
            else l = mid + 1;
        }
        pivot = r + 1;
        
        l = pivot, r = nums.size() - 1 + pivot;
        int n = nums.size();
        while(l <= r){
            
            int mid = (l + r)/2;
            
            if(nums[mid%n] > target) r = mid - 1;
            
            else if(nums[mid%n] == target) return mid%n;
            
            else l = mid + 1;
        }
        return -1;
    }
};
int32_t main(){
        FIO 

        return 0;
}
