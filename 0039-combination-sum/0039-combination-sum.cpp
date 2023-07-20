class Solution {
public:
    void solve(int ind,vector<int> ans,vector<vector<int>> &res,vector<int> &nums,int target){
        if(ind == nums.size()){
            if(!target) res.push_back(ans);
            return;
        }
        if(target >= nums[ind]){
            ans.push_back(nums[ind]);
            solve(ind,ans,res,nums,target-nums[ind]);
            ans.pop_back();
        }
        solve(ind+1,ans,res,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> res;
        solve(0,ans,res,candidates,target);
        return res;
    }
};