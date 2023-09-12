//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        string s="";
        if(N*9 < S) return "-1";
        if(S == 0 && N > 1) return "-1";
        while(S-9 >= 0){
            s+="9";
            S-=9;
        }
        if(S) s+=(S)+'0';
        while(s.size() < N) s+='0';
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends