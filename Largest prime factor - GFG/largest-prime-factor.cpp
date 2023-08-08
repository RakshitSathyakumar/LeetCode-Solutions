//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool isPrime(long long int x) {
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0)
                return false;
        }
        return x >= 2;
    }
    long long int largestPrimeFactor(int N){
        // code here
        vector<long long int> factors;
        for(int i=1;i*i<=N;i++){
            if(N%i == 0){
                factors.push_back(i);
                if(i * i != N){
                    factors.push_back(N/i);
                }
            }
        }
        long long int maxi=0;
        for(int i=0;i<factors.size();i++){
            if(isPrime(factors[i])){
                maxi=max(maxi,factors[i]);
            }
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends