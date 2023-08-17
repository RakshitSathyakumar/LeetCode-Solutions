class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0)),vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            auto front = q.front();q.pop();
            auto level = front.first;
            auto x = front.second.first,y=front.second.second;
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int i=0;i<4;i++){
                int nrow = dx[i]+x;
                int ncol = dy[i]+y;
                if(nrow<n && ncol <m && nrow >= 0 && ncol >=0 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=level+1;
                    q.push({level+1,{nrow,ncol}});
                    
                }
            }
        
        }

        return ans;
    }
};