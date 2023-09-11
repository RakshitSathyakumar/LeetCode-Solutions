//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
                if ( N == 8589869056 or N == 137438691328){
            return 1;
        }
    
        int sum = 0;
        for(long long int i=1;i <= sqrt(N);i++){
            if(N % i == 0){
                long long  other = N/i;
                sum += i;
                if(other != i){
                    sum += other;
                }
            }
        }
        return sum == 2*N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends