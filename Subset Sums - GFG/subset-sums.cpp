//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> nums, int N){
        vector<int> ans;
        int sum=0;
        function<void(int)> dfs=[&](int ind){
            if(ind == nums.size()){
                ans.push_back(sum);
                return;
            } 
            dfs(ind+1);
            sum+=nums[ind];
            dfs(ind+1);
            sum-=nums[ind];
        };
        dfs(0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends