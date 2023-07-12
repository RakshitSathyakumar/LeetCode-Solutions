class Solution {
public:
    void setRow(int i,int n,int m,vector<vector<int>> &matrix)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j])
            {
                matrix[i][j] = -1e9;
            }
        }
    }
    void setCol(int j,int n,int m,vector<vector<int>> &matrix)
    {
        for(int i=0;i<n;i++)
        {
            if(matrix[i][j])
            {
                matrix[i][j] = -1e9;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!matrix[i][j])
                {
                    setRow(i,n,m,matrix);
                    setCol(j,n,m,matrix);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == -1e9)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!matrix[i][j])
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i] || col[j])
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        // vector<int> row(n,0); --> matrix[..][0]
        // vector<int> col(m,0); -->matrix[0][..]
        int col0=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0]=0;
                    j !=0 ? matrix[0][j]=0 : col0=0;
                }
            }
        }
        for(int i=1;i<n;i++) for(int j=1;j<m;j++) if((!matrix[i][0] || !matrix[0][j])) matrix[i][j]=0;
        if(!matrix[0][0]) for(int i=1;i<m;i++) matrix[0][i]=0;
        if(!col0) for(int j=0;j<n;j++) matrix[j][0] = 0;

    }
};