class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int p = 0;
        
        int ans = -9999999;
        
        for(auto &x : nums)
            
            p += x, ans = max(ans, p), p = max(0, p);
        
        return ans;
        
    }
};