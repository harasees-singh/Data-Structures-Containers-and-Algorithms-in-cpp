#include<bits/stdc++.h>
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
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> answer(nums.size());
        
        int t = (int)nums.size() - 1;
        
        int pt1 = 0, pt2 = (int)nums.size() - 1;
        
        while(pt1 <= pt2){
            
            if(abs(nums[pt1]) > abs(nums[pt2]))
                
                answer[t] = nums[pt1]*nums[pt1], pt1++;
            
            else 
                
                answer[t] = nums[pt2]*nums[pt2], pt2--;
            
            t--;
                
        }
        
        return answer;
        
    }
};