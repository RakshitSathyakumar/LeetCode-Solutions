//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int l=0,r=m-1,cnt=1e9;
        vector<int> ans;
        while(l<n && r>=0){
            int sum=arr[l]+brr[r];
            
            int res=abs(sum-x);
            if(res < cnt){
                cnt=res;
                ans.clear();
                ans.push_back(arr[l]);
                ans.push_back(brr[r]);
            }
            
            if(sum>=x){
                // cnt=min(abs(sum-x),cnt);
                r--;
            }else{
                // cnt=min(abs(sum-x),cnt);
                l++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends