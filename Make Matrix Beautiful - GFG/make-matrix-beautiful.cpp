//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            int res1=0,res2=0;
            for(int j=0;j<n;j++){
                res1+=matrix[i][j];
                res2+=matrix[j][i];
            }
            sum1=max(sum1,res1);
            sum2=max(sum2,res2);
        }
        sum2=max(sum1,sum2);
        int cnt=0;
        for(int i=0;i<n;i++){
            int res=0;
            for(int j=0;j<n;j++){
                res+=matrix[i][j];
            }
            cnt+=(sum2-res);
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends