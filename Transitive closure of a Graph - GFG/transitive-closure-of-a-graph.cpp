//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis){
        vis[i]=1;
        for(auto itr:adj[i]){
            if(!vis[itr]){
                dfs(itr,adj,vis);
            }
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<int> adj[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        vector<vector<int>> ans(N,vector<int>(N,0));
        for(int i=0;i<N;i++){
            vector<int> vis(N,0);
            dfs(i,adj,vis);
            for(int j=0;j<N;j++){
                if(vis[j]) ans[i][j]=1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends