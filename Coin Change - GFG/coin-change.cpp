//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,0));
        for(int i=0;i<=N;i++){
            for(int j=0;j<=sum;j++){
                if(j==0) dp[i][j]=1;
            }
        }
        dp[0][0]=1;
        for(int i=1;i<=N;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=coins[i-1]){
                    dp[i][j]+=dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends