//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        if(sum%2) return 0;
        sum=sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=arr[i-1]) dp[i][j]=dp[i-1][j] | dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends