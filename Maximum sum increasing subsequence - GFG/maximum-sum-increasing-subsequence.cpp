//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n,1);
	    vector<int> sum(n,0);
	   // sum[0]=arr[0];
	   for(int i=0;i<n;i++) sum[i]=arr[i];
	    for(int i=0;i<n;i++){
	   
	        for(int j=0;j<i;j++){
	            if(arr[i] > arr[j]){
	                dp[i]=dp[j]+1;
	               if(sum[j]+arr[i] > sum[i]) sum[i] = sum[j]+arr[i];
	            }
	        }
	    }
	    int maxi=0;
	    for(auto itr:sum) maxi=max(maxi,itr);
	    return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends