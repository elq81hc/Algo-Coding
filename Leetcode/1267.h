class Solution
{
public:
    // * * *
    // * * *
    int countServers(vector<vector<int>> &grid)
    {
        int n = grid.size();    // col
        int m = grid[0].size(); // row
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                {
                    col[i]++;
                    row[j]++;
                }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && (row[j] + col[i] > 2)) {
                    ans++;
                }
            }
        }        
        return ans;
    }
};