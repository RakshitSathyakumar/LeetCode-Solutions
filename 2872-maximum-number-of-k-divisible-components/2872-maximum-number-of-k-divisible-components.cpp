class Solution {
public:
    
    int dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &values,int k,int &cnt){
        
        vis[node]=1;
        int sum=values[node];
        
        for(auto itr:adj[node]){
            if(!vis[itr]){
                sum+=dfs(itr,vis,adj,values,k,cnt);
            }
        }
        // cout<<cnt<<endl;
        if(sum % k == 0){
            cnt++;
            sum=0;
            return 0;
        }
        // sum-=values[node];
        return sum;
        
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        vector<int> vis(n,0);
        int maxi=0;
        // for(int i=0;i<edges.size();i++){
            int cnt=0,sum=0;
            dfs(0,vis,adj,values,k,cnt);
            // maxi=max(maxi,cnt);
        
        // if(sum%k) return 1;
        // cout<<sum<<endl;
        // }
        return cnt;
    }
};