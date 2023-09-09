class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(auto itr:nums){
                if(i >= itr){
                    dp[i]+=dp[i-itr];
                }
            }
        }
        return dp[target];
    }
};