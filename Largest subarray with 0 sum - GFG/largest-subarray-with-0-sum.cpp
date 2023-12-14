//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n){   
        // Your code here
        map<long long,long long> mp;
        long long sum=0,maxi=0,k=0;
        mp[0]=0;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            if(sum==k){
                maxi=max(maxi,(i+1)*1LL);
            }if(mp.find(sum-k) != mp.end()){
                maxi=max(maxi,i-mp[sum-k]);
            }if(mp.find(sum) != mp.end()){
                continue;
            }
            mp[sum]=i;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends