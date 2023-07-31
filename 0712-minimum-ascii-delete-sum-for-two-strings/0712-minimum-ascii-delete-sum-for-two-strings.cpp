class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = s[i-1] + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        // string ans;
        // int i=n,j=m;
        // while(i>=1 && j>=1)
        // {
        //     if(s[i-1] == t[j-1])
        //     {
        //         ans +=s[i-1];
        //         i--,j--;
        //     }
        //     else
        //     {
        //         if(dp[i-1][j] > dp[i][j-1])
        //         {
        //             i--;
        //         }
        //         else if(dp[i][j-1] > dp[i-1][j])
        //         {
        //             j--;
        //         }
        //         else
        //         {
        //             if((int)s[i-1] > (int)t[j-1])
        //             {
        //                 j--;
        //             }
        //             else
        //             {
        //                 i--;
        //             }
        //         }
        //     }
        // }
        // cout<<ans<<' ';
        // reverse(ans.begin(),ans.end())/;
        // string t=ans;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            cnt+= (int)s[i];
        }
        for(auto x:t)
        {
            cnt+=(int)x;
        }
        // int temp=0;
        // for(auto x:ans)
        // {
        //     temp+=(int)x;
        // }

        return cnt - 2*dp[n][m];

    }
};