// wrong approach because we used the '/' operator which was not allowed

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int cnzero = 0;
        
        int p = 1;
        
        int zeroindex;
        
        for(int i = 0; i < nums.size(); i++){
            
                cnzero += (nums[i] == 0);
            
                p *= (nums[i] == 0 ? 1 : nums[i]);
        
                if(nums[i] == 0) zeroindex = i;
        }
        
        if(cnzero >= 2){
            
            for(auto &x : nums) x = 0;
        
            return nums;
        }
        int i = 0;
        
        if(cnzero == 1){
            
            for(auto &x : nums) x = 0;
            
            nums[zeroindex] = p;
        
        }
        
        else
        
            for(auto &x : nums) x = p/x, i++;
            
            
        return nums;
            
    }
};

// correct approach

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size());
        
        ans[nums.size() - 1] = nums[nums.size() - 1];
        
        for(int i = (int)nums.size() - 2; i >= 0; i--){
            
            ans[i] = ans[i + 1]*nums[i];
        }
        
        int p = 1;
        
        for(int i = 0; i < (int)nums.size() - 1; i++)
            
            ans[i] = p*ans[i + 1], p*=nums[i];
        
        ans[ans.size() - 1] = p;
        
        return ans;
    }
};