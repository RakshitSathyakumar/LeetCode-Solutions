//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        vector<vector<int>> vis(N,vector<int>(M,0));
        while(!q.empty()){
            auto front = q.front();q.pop();
            auto steps = front.first;
            auto x = front.second.first , y = front.second.second;
            vis[x][y] = 1;
            if(x == X && y == Y){
                return steps;
            }
            int dx[]={1,-1,0,0};
            int dy[] = {0,0,1,-1};
            for(int i=0;i<4;i++){
                int nrow = x + dx[i] , ncol = y + dy[i];
                if(nrow >=0 && nrow < N && ncol >=0 && ncol < M && !vis[nrow][ncol] && A[nrow][ncol]){
                    q.push({steps+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends