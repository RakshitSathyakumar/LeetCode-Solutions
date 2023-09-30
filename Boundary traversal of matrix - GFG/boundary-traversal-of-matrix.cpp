//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
               vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int count=0;
        int startrow = 0, startcol = 0, endrow = row-1, endcol = col-1;
    
    
        //print starting row
        for(int i=startcol;count < total && i<=endcol;i++){
            ans.push_back(matrix[startrow][i]);
            count++;
        }
        startrow++;
        
        //print ending column
        for(int i = startrow;count < total && i<=endrow; i++){
            ans.push_back(matrix[i][endcol]);
            count++;
        }
        endcol--;
        
        //print end row
        for(int i = endcol ;count < total && i>=startcol; i--){
            ans.push_back(matrix[endrow][i]);
            count++;
        }
        endrow--;
        
        //print start col
        for(int i = endrow;count < total && i>= startrow;i--){
            ans.push_back(matrix[i][startcol]);
            count++;
        }
        startcol++;
    
    return ans;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends