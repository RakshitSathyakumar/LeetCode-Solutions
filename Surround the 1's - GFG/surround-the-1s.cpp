//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
       int n=matrix.size(),m=matrix[0].size();
       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]) q.push({i,j});
           }
       }
       int cnt=0;
       while(!q.empty()){
           auto front = q.front();q.pop();
           auto row=front.first,col=front.second;
           int dx[]={-1,1,0,0,1,1,-1,-1};
           int dy[]={0,0,1,-1,1,-1,1,-1};
           int t=0;
           for(int i=0;i<8;i++){
               int nrow=row+dx[i];
               int ncol=col+dy[i];
               if(nrow >=0 && ncol >=0 && nrow<n &&ncol<m && !matrix[nrow][ncol]){
                   t++;
               }
           }
           if(t%2==0 && t>0){
               cnt++;
           }
       }
       return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends