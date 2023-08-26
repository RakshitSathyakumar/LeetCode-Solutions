class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int> dp(n+1,1);
        sort(pairs.begin(),pairs.end());
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        for(auto itr:dp) cout<<itr<<' ';
        return maxi;
    }
};