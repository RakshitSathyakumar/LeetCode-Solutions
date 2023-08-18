class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n+1];
        for(auto itr:roads){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = adj[i].size()+adj[j].size();
                for(auto k:adj[i]){
                    if(k == j){
                        x--;
                        break;
                    }
                }
                cnt=max(cnt,x);
            }
        }
        return cnt;
    }
};