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
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE
#include<bits/stdc++.h>
#define vi vector<int>


int solve(vector<int>& nums) {

        if(nums.size() == 1 or nums.size() == 0)
                return 0;
    

        int cnt = 0;

        int n = nums.size();

        int prev = 0;

        int curr = 0;

        while(true){
                if(curr + nums[curr] >= n - 1)
                        return 1 + cnt;

                int maxi = 0;
                int id;
                
                for(int i = prev + 1; i <= curr + nums[curr]; i++){

                        if(i + nums[i] >= maxi)
                                maxi = i + nums[i], id = i;
                }
                prev = curr;
                curr = id;
                
                cnt++;
        }
}
int32_t main(){
    FIO 

    return 0;
}
