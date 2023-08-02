class Solution {
public:
    void solve(int ind,vector<int> ans, vector<vector<int>> &res,vector<int> nums,vector<int> vis){
        if(ans.size() == nums.size()){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                ans.push_back(nums[i]);
                vis[i]=1;
                solve(i+1,ans,res,nums,vis);
                ans.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans,vis(nums.size(),0);
        vector<vector<int>> res;
        solve(0,ans,res,nums,vis);
        return res;
    }
};