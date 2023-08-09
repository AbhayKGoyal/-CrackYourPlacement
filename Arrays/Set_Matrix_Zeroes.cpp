// https://leetcode.com/problems/set-matrix-zeroes/

// Approach 1 (Naive)
class Solution {
public:
    void help(int a, int b, vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
            matrix[i][b] = 0;
        for(int i = 0; i < n; i++)
            matrix[a][i] = 0;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> v;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                    v.push_back({i, j});

        for(auto p : v)
            help(p.first, p.second, matrix);
    }
};


// Approach 2 (Better)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, -1);
        vector<int> column(n, -1);
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                {
                    row[i] = 0;
                    column[j] = 0;
                }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(row[i] == 0 || column[j] == 0)
                    matrix[i][j] = 0;
                    
    }
};

// Approach 3 (Best One)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 9087;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(j == 0)
                        x = 0;
                    else
                    {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        
        // Whole Matrix else 1st row & first column
        for(int i = m-1; i > 0; --i)
        {
            for(int j = n-1; j > 0; --j)
            {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Only first row except 0th element
        if(matrix[0][0] == 0)
        for(int i = 1; i < n; i++)
        {
            matrix[0][i] = 0;
        }
        
        // check if first colmn needs to be zero also
        if(x == 0)
        for(int j = 0; j < m; j++)
            matrix[j][0] = 0;
    }
};
