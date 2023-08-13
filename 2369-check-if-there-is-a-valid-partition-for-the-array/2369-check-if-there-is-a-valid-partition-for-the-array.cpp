class Solution {
public:
    bool f(int ind,vector<int> &nums,vector<int> &dp){
        if(ind == nums.size() - 1) return false;
        if(ind == nums.size()) return true;
        if(ind > nums.size()) return false;
        
        if(dp[ind] != -1) return dp[ind];
        bool op1=false,op2=false,op3=false;

        if(ind+1 < nums.size() && nums[ind] == nums[ind+1]) op1=f(ind+2,nums,dp);
        if(ind+2 < nums.size() && nums[ind] == nums[ind+1] && nums[ind] == nums[ind+2]) op2=f(ind+3,nums,dp);
        if(ind+2 < nums.size() && nums[ind+1] - nums[ind] == 1 && nums[ind+2] - nums[ind+1] == 1 )op3=f(ind+3,nums,dp);

        return dp[ind] = op1 | op2 | op3;
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return f(0,nums,dp);
    }
};