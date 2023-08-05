//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int ind,string ans,string S,vector<string> &vs,vector<int> &vis){
        if(ans.size() == S.size()){
            vs.push_back(ans);
            return;
        }
        for(int i=0;i<S.size();i++){
            if(!vis[i]){
                ans.push_back(S[i]);
                vis[i] =1;
                solve(i+1,ans,S,vs,vis);
                ans.pop_back();
                vis[i] = 0;
            }
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> vs;
        sort(S.begin(),S.end());
        string ans;
        vector<int> vis(S.size(),0);
        solve(0,ans,S,vs,vis);
        sort(vs.begin(),vs.end());
        return vs;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends