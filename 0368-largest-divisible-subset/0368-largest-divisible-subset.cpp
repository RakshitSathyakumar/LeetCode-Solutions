class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n+1,1),ans,prev(n+1,-1);
        int maxi=0,index=-1;
        for(int i=0;i<n;i++){
            // dp[i]=1;
            // prev[i]=-1;
            for(int prevs = i-1;prevs>=0;prevs--){
                if(nums[i]%nums[prevs] == 0){
                    if(dp[prevs]+1 > dp[i]){
                        dp[i]=dp[prevs]+1;
                        prev[i] = prevs;
                    }
                }
            }
            if(dp[i] > maxi){
                maxi=dp[i];
                index=i;
            }
        }
        cout<< index;
        while(index != -1){
            ans.push_back(nums[index]);
            index=prev[index];
        }
        return ans;
    }
};