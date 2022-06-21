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
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int mj1 = 1e9 + 1, mj2 = 1e9 + 1;
        
        for(auto p : nums){
            if(p == mj1) cnt1++;
            else if(p == mj2) cnt2++;
            else if(cnt1 == 0) mj1 = p, cnt1 = 1;
            else if(cnt2 == 0) mj2 = p, cnt2 = 1;
            else cnt1--, cnt2--;
        }
        int cnt = 0;
        for(auto p : nums) if(p == mj1) cnt++;
        if(cnt > n/3) ret.push_back(mj1);
        cnt = 0;
        for(auto p : nums) if(p == mj2) cnt++;
        if(cnt > n/3) ret.push_back(mj2);
        return ret;
    }
};
int32_t main(){
        FIO 

        return 0;
}
