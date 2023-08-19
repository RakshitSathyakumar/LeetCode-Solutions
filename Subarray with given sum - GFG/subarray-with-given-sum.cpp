//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> ans;
        int i=0,j=0;
        long long res=0;
        while(j<n){
            res+=arr[j];
            if(res < s){
                j++;
            }else if(res >= s){
                while(i<j && res > s){
                    res-=arr[i];
                    i++;
                }   
                if(res == s){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    break;
                }
                j++;
            }
        }
        vector<int> temp={-1};
        return ans.size() == 0 ? temp : ans;
        // return pref;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends