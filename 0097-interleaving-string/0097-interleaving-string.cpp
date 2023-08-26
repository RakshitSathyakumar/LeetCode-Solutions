class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int n=a.size(),m=b.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        if(n+m != c.size()) return false;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 && j==0){
                    dp[i][j]=1;
                }else if(j==0){
                    if(a[i-1] == c[i+j-1]) dp[i][j]=dp[i-1][j];
                }else if(i==0){
                    if(b[j-1] == c[i+j-1]) dp[i][j]=dp[i][j-1];
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[j-1] != c[i+j-1] && a[i-1] == c[i+j-1]){
                    dp[i][j] = dp[i-1][j];
                }else if(a[i-1] != c[i+j-1] && b[j-1] == c[i+j-1]){
                    dp[i][j] = dp[i][j-1];
                }else if(a[i-1] == c[i+j-1] && b[j-1] == c[i+j-1]){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }else{
                    dp[i][j]=0;
                }
            } 
        }
        return dp[n][m];
    }
};