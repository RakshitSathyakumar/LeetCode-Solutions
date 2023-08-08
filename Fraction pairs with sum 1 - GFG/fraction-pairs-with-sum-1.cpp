//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int deno[])
    {
        for(int i=0;i<n;i++){
            int factor = __gcd(num[i],deno[i]);
            num[i]/=factor;
            deno[i]/=factor;
        }
        int cnt =0;
        map<pair<int,int> , int > mp;
        for(int i=0;i<n;i++){
            if(mp.find({deno[i]-num[i],deno[i]})!=mp.end()){
                cnt += mp[{deno[i]-num[i],deno[i]}];
            }
            mp[{num[i],deno[i]}]++;
        }
        return cnt;
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
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends